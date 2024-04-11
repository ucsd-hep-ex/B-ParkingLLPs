#!/bin/bash

# Flag to control the creation of resubmit files. Set to true to create, false to just report missing files.
CREATE_RESUBMIT_FILE=false

# Define the paths to the directories
listDir="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/lists/V1p19_7"
rootDir="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/WP5"

# Loop through each .list file in the first directory
for listFile in "$listDir"/*.list; do
    # Extract the base name of the list file
    baseName=$(basename "$listFile" .list)
    
    # Count the number of lines in the list file
    numLines=$(wc -l < "$listFile")
    
    # Calculate the last index (1 - number of lines)
    lastIndex=$((numLines - 1))

    # Initialize variable to store missing file indices
    missingFiles=()

    echo "Checking files for $baseName, expecting $numLines files..."
    
    # Check each file in the range from 0000000 to the last index
    for ((i=0; i<=lastIndex; i++)); do
        # Format the file number with leading zeros
        formattedIndex=$(printf "%07d" $i)
        
        # Construct the expected file name
        expectedFile="$rootDir/$baseName/${baseName}_${formattedIndex}to_nominal_plots.root"
        
        # Check if the expected file does not exist
        if [ ! -f "$expectedFile" ]; then
            echo "Missing: $expectedFile"
            missingFiles+=($formattedIndex)
        fi
    done

    # If CREATE_RESUBMIT_FILE is true and there are missing files, create a resubmit file
    if [ "$CREATE_RESUBMIT_FILE" = true ] && [ ${#missingFiles[@]} -gt 0 ]; then
        resubmitFilePath="$rootDir/$baseName/resubmitfile"
        echo "Creating $resubmitFilePath..."
        
        # Write the common part of the resubmit file
        cat > "$resubmitFilePath" <<EOF
universe = vanilla
Executable = /uscms_data/d3/ddiaz/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/runJobs.sh
Should_Transfer_Files = YES  
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = ../RunAnalyzer.exe
notify_user = ddiaz@cern.ch
x509userproxy = /uscms/home/ddiaz/x509up_u52877

Output = logs/runanalyzer_$(Cluster)_$(Process).stdout
Error  = logs/runanalyzer_$(Cluster)_$(Process).stderr
Log    = logs/runanalyzer_$(Cluster)_$(Process).log
EOF
        
        # Add an Arguments line and Queue command for each missing file
        for index in "${missingFiles[@]}"; do
            echo "Arguments = root://cmsxrootd.fnal.gov//store/group/lpclonglived/B-ParkingLLPs/V1p19_7/$baseName/ $baseName""_${index}" >> "$resubmitFilePath"
            echo "Queue" >> "$resubmitFilePath"
        done
    fi
done

