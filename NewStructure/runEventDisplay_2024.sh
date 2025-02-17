#! /bin/bash
dataDirOut=""
runNr=""
if [ $1 = "fbock" ]; then 
	if [ $2 = "muon" ]; then
		dataDirOut=/home/fbock/EIC/Analysis/LFHCalTB2024/CAENdata/MuonRuns
		runNr=$6
	elif [ $2 = "electron" ]; then
		dataDirOut=/home/fbock/EIC/Analysis/LFHCalTB2024/CAENdata/ElectronRuns
		runNr=$6
	elif [ $2 = "hadron" ]; then
		dataDirOut=/home/fbock/EIC/Analysis/LFHCalTB2024/CAENdata/HadronRuns
		runNr=$6
	else 
		echo "Please select a beam type (muon, electron, or hadron), otherwise I don't know where the data is"
		exit
	fi
elif [ $1 = "eglimos" ]; then 
	if [ $2 = "muon" ]; then
		dataDirOut=/home/ewa/EIC/test_beam2024/fullScanC/Output/MuonRuns
		runNr=376
	elif [ $2 = "electron" ]; then
		dataDirOut=/home/ewa/EIC/test_beam2024/fullScanC/Output/ElectronRuns
		runNr=379
	elif [ $2 = "hadron" ]; then
		dataDirOut=/home/ewa/EIC/test_beam2024/fullScanC/Output/HadronRuns
		runNr=397
	else 
		echo "Please select a beam type (muon, electron, or hadron), otherwise I don't know where the data is"
		exit
	fi
else
	echo "Please select a known user name, otherwise I don't know where the data is"
	exit
fi

runNrFile='../configs/DataTakingDB_202409_CAEN.csv'

if [ $5 == "muonTrig" ]; then
	./Display -i $dataDirOut/calibrated_Run_$runNr.root -r $runNrFile -P ../3DPlot/Run_$runNr/MuonTrig -e $3 -N $4 -M -d 2
else
	./Display -i $dataDirOut/calibrated_Run_$runNr.root -r $runNrFile -P ../3DPlot/Run_$runNr -e $3 -N $4 -d 2
fi 

