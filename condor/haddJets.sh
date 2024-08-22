#######################################################################
# Use this script to hadd the Jets.root files made by the analyzer code
#######################################################################

versionName=${version}
base_dir=${CMSSW_BASE}/src/B-ParkingLLPs/condor/gitignore

for dir in $base_dir/$versionName/P*
do
  echo $dir
  touch tmpJ.sh
  echo hadd $dir/haddJets.root \\ > tmpJ.sh
  count=0
  chunk=1
  for f in $dir/Jets*.root 
  do
    if [ $count -ge 199 ]; then
      echo "Processing chunk $chunk in $dir"
      bash tmpJ.sh
      rm -f tmpJ.sh
      touch tmpJ.sh
      echo hadd $dir/haddJets_part${chunk}.root \\ > tmpJ.sh
      count=0
      chunk=$((chunk + 1))
    fi
    echo $f \\ >> tmpJ.sh
    count=$((count + 1))
  done
  # Final chunk
  if [ $count -gt 0 ]; then
    bash tmpJ.sh
    mv $dir/haddJets.root $dir/haddJets_part${chunk}.root
  fi
  rm -f tmpJ.sh
done

echo "******* Now merge all *****"

touch tmpJ.sh
echo hadd ${base_dir}/${version}/Jets.root \\ > tmpJ.sh
for dir in $base_dir/$versionName/P*
do
  for hadded in $dir/haddJets_part*.root
  do
    echo $hadded \\ >> tmpJ.sh
  done
done
bash tmpJ.sh
rm -f tmpJ.sh

