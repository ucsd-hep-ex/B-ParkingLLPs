//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Sep  1 02:22:32 2022 by ROOT version 6.24/06
// from TTree MuonSystem/MuonSystem
// found on file: BToKPhi_MuonGenFilter_mPhi1p0_ctau1000_1pb_weighted.root
//////////////////////////////////////////////////////////

#ifndef analyzer_h
#define analyzer_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "cJSON.h"
#include <unordered_map>

#include "analyzer_histograms.h"

class analyzer : public analyzer_histograms {
public :
   //TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   //Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   analyzer();
   virtual ~analyzer();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   //virtual Long64_t LoadTree(Long64_t entry);
   //virtual void     Init(TTree *tree);
   virtual void     Loop(TFile *f, Float_t from_ctau, Float_t to_ctau, TString theSample, Float_t NEvents);
   //virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   bool doesPassHLT(); 
   void loadLumiJSON();
   bool goodLumi(int run, int lumi);

private:
   struct LumiRange {
       int start;
       int end;
   };
   std::unordered_map<int, std::vector<LumiRange>> runLumiMap;
   bool isWithinRange(int lumi, int start, int end);
};

#endif

#ifdef analyzer_cxx


Int_t analyzer::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}



void analyzer::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analyzer::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

bool analyzer::doesPassHLT(){
  bool doesPass = false;
  for (int t= HLTIndexLow; t <= HLTIndexHigh; t++){
    if (HLTDecision[t]) {doesPass = true; continue;}
  }
  return doesPass;
}

void analyzer::loadLumiJSON() {
  std::ifstream file(theLumiJSON);
    if (!file.is_open()) {
      std::cerr << "Failed to open file: " << theLumiJSON << std::endl;
    }

    // Read the entire file into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();

    // Parse the JSON data
    cJSON* json = cJSON_Parse(data.c_str());
    if (json == nullptr) {
      std::cerr << "Failed to parse JSON" << std::endl;
    }

    // Iterate over each key-value pair in the JSON object
    cJSON* runJson = nullptr;
    cJSON_ArrayForEach(runJson, json) {
      int run = std::stoi(runJson->string);
      if (!cJSON_IsArray(runJson)) {
        continue;
      }
      // Parse each lumi range for this run
      std::vector<LumiRange> ranges;
      cJSON* range = nullptr;
      cJSON_ArrayForEach(range, runJson) {
        if (cJSON_IsArray(range) && cJSON_GetArraySize(range) == 2) {
          int start = cJSON_GetArrayItem(range, 0)->valueint;
          int end = cJSON_GetArrayItem(range, 1)->valueint;
          ranges.push_back({start, end});
        }
      }
      // Store the run and its lumi ranges in the map
      runLumiMap[run] = ranges;
    }
    cJSON_Delete(json);
}

bool analyzer::isWithinRange(int lumi, int start, int end) {
  return lumi >= start && lumi <= end;
}

bool analyzer::goodLumi(int run, int lumi) {
  if (runLumiMap.find(run) == runLumiMap.end()) {
    return false; // Run not found
  }

  const std::vector<LumiRange>& ranges = runLumiMap[run];
  for (const LumiRange& range : ranges) {
    if (isWithinRange(lumi, range.start, range.end)) {
        return true;
    }
  }
  return false;
}

#endif // #ifdef analyzer_cxx
