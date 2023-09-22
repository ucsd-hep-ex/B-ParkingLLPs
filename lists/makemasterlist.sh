#!/bin/bash

# define output directory where lists will end up
outdir="${CMSSW_BASE}/src/B-ParkingLLPs/lists"

# read first layer of storage directory save output to temp file
xrdfs root://cmseos.fnal.gov ls /eos/uscms/store/group/lpclonglived/B-ParkingLLPs/V1p19_7/ > templayer1.out

# initialize outfile as empty (overwrite if exists)
echo "" > ${outdir}/allfiles.masterlist

# read subsequent layers into temp files until arrive at root file
for lineone in $(cat templayer1.out);
do
 if [[ ${lineone} == *"analyzed"* ]]; then
   continue
 fi
 xrdfs root://cmseos.fnal.gov ls ${lineone} >> ${outdir}/allfiles.masterlist 
 echo "Text read from file: ${lineone}"
 #for linetwo in $(cat templayer2.out)
 #do
 # xrdfs root://cmseos.fnal.gov ls ${linetwo} >> ${outdir}/allfiles.masterlist
 #done
done

#remove bad entries from masterlist
sed -i '/-hadd/d' ${outdir}/allfiles.masterlist
sed -i '/A.root/d' ${outdir}/allfiles.masterlist
sed -i '/B.root/d' ${outdir}/allfiles.masterlist
sed -i '/C.root/d' ${outdir}/allfiles.masterlist
sed -i '/D.root/d' ${outdir}/allfiles.masterlist
# This because, for signal the hadding worked
# so will just do one job instead of 100's 
sed -i '/ctau300_/d' ${outdir}/allfiles.masterlist
sed -i '/ctau1000_/d' ${outdir}/allfiles.masterlist
#save master list and remove junk files
mv templayer1.out ${outdir}/dir.out
rm -f templayer2.out
rm -f templayer3.out
rm -f templayer4.out
