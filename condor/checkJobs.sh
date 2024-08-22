#!/bin/bash
################################################################
#  Use this to check job completion when using the analyzer code
################################################################


# Flag to control the creation of resubmit files. Set to true to create, false to just report missing files.
CREATE_RESUBMIT_FILE=false
NTVname="FR" #"FR"  #"V1p19_9"
# Define the paths to the directories
listDir="${CMSSW_BASE}/src/B-ParkingLLPs/lists/${NTVname}"
rootDir="${CMSSW_BASE}/src/B-ParkingLLPs/condor/gitignore/${version}" 

# Define a blacklist of baseNames (or patterns) to skip
# Script no supported for signal, so add those here
blacklist=(\
  "EGamma_2018"\
  "SingleMuon"\
  "SingleElectron"\
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau3000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau500" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p5_ctau5000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau10000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau300" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau10000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau10000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau3000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau5000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau10000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau10000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau10000" \
  "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000" \
)
echo "version name: ${version}"
echo checking in ${rootDir}
# Loop through each .list file in the first directory
for listFile in "$listDir"/*.list; do
    # Extract the base name of the list file
    baseName=$(basename "$listFile" .list)

    # Flag indicating if current baseName is blacklisted
    skip=false
    
    # Check against blacklist patterns
    for pattern in "${blacklist[@]}"; do
        if [[ $baseName == *$pattern* ]]; then
            echo "Skipping $baseName as it matches blacklist pattern $pattern."
            skip=true
            break
        fi
    done

    # Skip this iteration if baseName is blacklisted
    if [[ $skip == true ]]; then
        continue
    fi

    echo "Checking files for $baseName based on indices in $listFile..."

    # Initialize an array to store missing indices
    missingFiles=()

    # Read through each line in the list file
    while IFS= read -r line; do
        index=$(echo "$line" | grep -oP '(?<=_)\d+$') # for FR
        formattedIndex=$(printf "%07d" "$((10#$index))")

        # Construct the expected file name
        expectedFile="$rootDir/$baseName/${baseName}_${formattedIndex}to_nominal_plots.root"

        # Check if the expected file does not exist
        if [ ! -f "$expectedFile" ]; then
            echo "Missing: $expectedFile"
            missingFiles+=($formattedIndex)
        fi
    done < "$listFile"

    # If CREATE_RESUBMIT_FILE is true and there are missing files, create a resubmit file
    if [ "$CREATE_RESUBMIT_FILE" = true ] && [ ${#missingFiles[@]} -gt 0 ]; then
        resubmitFilePath="$rootDir/$baseName/resubmitfile"
        echo "Creating $resubmitFilePath..."

        # Write the common part of the resubmit file
        cat > "$resubmitFilePath" <<EOF
universe = vanilla
Executable = ${CMSSW_BASE}/src/B-ParkingLLPs/condor/runJobs.sh
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
            echo "Arguments = root://cmsxrootd.fnal.gov//store/group/lpclonglived/B-ParkingLLPs/${NTVname}/$baseName/ $baseName""_${index}" >> "$resubmitFilePath"
            echo "Queue" >> "$resubmitFilePath"
        done
    fi
done

