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
   void loadEfficiencyJSON();
   void getEfficiency(Float_t pt, Float_t abseta, Float_t& value, Float_t& error);


private:
   struct LumiRange {
       int start;
       int end;
   };
    struct PtBin {
        float pt_min;
        float pt_max;
        float value;
        float error;
    };

    struct AbsetaBin {
        float abseta_min;
        float abseta_max;
        std::vector<PtBin> pt_bins;
    };
   std::vector<AbsetaBin> abseta_bins;
   std::unordered_map<int, std::vector<LumiRange>> runLumiMap;
   bool isWithinRange(int lumi, int start, int end);
   cJSON* efficiencyRoot;
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





/// lepton ID Eff SFs
void analyzer::loadEfficiencyJSON() {
    // Open the JSON file
    std::ifstream file(thelepIDJSON);
    if (!file.is_open()) {
        std::cerr << "Failed to open efficiency JSON file: " << thelepIDJSON << std::endl;
        return;
    }

    // Read the entire file into a string
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string data = buffer.str();

    // Parse the JSON data
    cJSON* json = cJSON_Parse(data.c_str());
    if (json == nullptr) {
        std::cerr << "Failed to parse efficiency JSON: " << cJSON_GetErrorPtr() << std::endl;
        return;
    }
    // Access the "NUM_SoftID_DEN_genTracks" object
    cJSON* softID = cJSON_GetObjectItem(json, "NUM_SoftID_DEN_genTracks");
    if (!softID) {
        std::cerr << "NUM_SoftID_DEN_genTracks not found in efficiency JSON." << std::endl;
        cJSON_Delete(json);
        return;
    }

    cJSON* abseta_pt = cJSON_GetObjectItem(softID, "abseta_pt");
    if (!abseta_pt) {
        std::cerr << "abseta_pt not found in efficiency JSON." << std::endl;
        cJSON_Delete(json);
        return;
    }

    // Iterate over abseta bins
    cJSON* abseta_bin = nullptr;
    cJSON_ArrayForEach(abseta_bin, abseta_pt) {
        const char* abseta_key = abseta_bin->string;
        float abseta_min, abseta_max;

        // Parse the abseta range from the key
        if (sscanf(abseta_key, "abseta:[%f,%f]", &abseta_min, &abseta_max) != 2) {
            std::cerr << "Error parsing abseta range from key: " << abseta_key << std::endl;
            continue;
        }

        AbsetaBin absetaBin;
        absetaBin.abseta_min = abseta_min;
        absetaBin.abseta_max = abseta_max;

        // Iterate over pt bins within this abseta bin
        cJSON* pt_bin = nullptr;
        cJSON_ArrayForEach(pt_bin, abseta_bin) {
            const char* pt_key = pt_bin->string;
            float pt_min, pt_max;

            // Parse the pt range from the key
            if (sscanf(pt_key, "pt:[%f,%f]", &pt_min, &pt_max) != 2) {
                std::cerr << "Error parsing pt range from key: " << pt_key << std::endl;
                continue;
            }
            PtBin ptBin;
            ptBin.pt_min = pt_min;
            ptBin.pt_max = pt_max;

            // Get the value and error
            cJSON* value_item = cJSON_GetObjectItem(pt_bin, "value");
            cJSON* error_item = cJSON_GetObjectItem(pt_bin, "error");

            if (value_item && error_item) {
                ptBin.value = static_cast<float>(value_item->valuedouble);
                ptBin.error = static_cast<float>(error_item->valuedouble);
                absetaBin.pt_bins.push_back(ptBin);
            } else {
                std::cerr << "Value or error not found in pt bin: " << pt_key << std::endl;
            }
        }

        // Add the absetaBin to the vector
        abseta_bins.push_back(absetaBin);
    }

    cJSON_Delete(json);
}


void analyzer::getEfficiency(Float_t pt, Float_t abseta, Float_t& value, Float_t& error) {
    for (const auto& absetaBin : abseta_bins) {
        if (abseta >= absetaBin.abseta_min && abseta <= absetaBin.abseta_max) {
            // Found matching abseta bin
            for (const auto& ptBin : absetaBin.pt_bins) {
                if (pt >= ptBin.pt_min && pt <= ptBin.pt_max) {
                    // Found matching pt bin
                    value = ptBin.value;
                    error = ptBin.error;
                    return;
                }
            }
            // No matching pt bin found within this abseta bin
            return;
        }
    }
    // No matching abseta bin found
    return;
}


#endif // #ifdef analyzer_cxx
