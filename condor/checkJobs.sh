#!/bin/bash

# Define the paths to the directories
listDir="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/lists/V1p19_7"
rootDir="/uscms/home/ddiaz/nobackup/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/gitignore/DPhi2p8Both"
executablePath="/uscms_data/d3/ddiaz/BParkingLLPs/CMSSW_9_4_4/src/B-ParkingLLPs/condor/runJobs.sh"

# Loop through each .list file in the first directory
for listFile in "$listDir"/*.list; do
    baseName=$(basename "$listFile" .list)
    numLines=$(wc -l < "$listFile")
    lastIndex=$((numLines - 1))
    missingFiles=0
    
    # Path for the resubmit file
    resubmitFilePath="$rootDir/$baseName/resubmitfile"

    # Check each file in the range from 0000000 to the last index
    for ((i=0; i<=lastIndex; i++)); do
        formattedIndex=$(printf "%07d" $i)
        expectedFile="$rootDir/$baseName/${baseName}_${formattedIndex}to_nominal_plots.root"
        
        if [ ! -f "$expectedFile" ]; then
            if [ $missingFiles -eq 0 ]; then
                # Initialize the resubmitfile if it's the first missing file
                mkdir -p "$rootDir/$baseName/logs" # Ensure the logs directory exists
                echo "universe = vanilla
Executable = $executablePath
Should_Transfer_Files = YES
WhenToTransferOutput = ON_EXIT
Transfer_Input_Files = ../RunAnalyzer.exe
notify_user = ddiaz@cern.ch
x509userproxy = /uscms/home/ddiaz/x509up_u52877

Output = logs/runanalyzer_\$(Cluster)_\$(Process).stdout
Error  = logs/runanalyzer_\$(Cluster)_\$(Process).stderr
Log    = logs/runanalyzer_\$(Cluster)_\$(Process).log" > "$resubmitFilePath"
            fi
            # Append the arguments and queue line for the missing file
            echo "
Arguments = root://cmsxrootd.fnal.gov//store/group/lpclonglived/B-ParkingLLPs/V1p19_7/${baseName}/ ${baseName}_${formattedIndex} 
Queue" >> "$resubmitFilePath"
            
            ((missingFiles++))
        fi
    done
    
    if [ $missingFiles -gt 0 ]; then
        echo "Created resubmitfile for $baseName with $missingFiles missing files."
    fi
done

