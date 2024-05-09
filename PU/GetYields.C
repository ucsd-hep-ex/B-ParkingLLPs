/*
 *  run root -l -b -q
 *  Assumes you have created three versions of the input root file that uses either the nominal,
 *  or the up/down variation of the correction you are exploring
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <TFile.h>
#include <TH1.h>

// Function to get histogram content and error from a specific file
bool getHistogramData(const char* filename, const char* histName, int bin, double &content, double &error) {
    TFile file(filename);
    if (file.IsZombie()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }
    TH1* hist = dynamic_cast<TH1*>(file.Get(histName));
    if (!hist) {
        std::cerr << "Histogram " << histName << " not found in file " << filename << std::endl;
        return false;
    }
    content = hist->GetBinContent(bin);
    error = hist->GetBinError(bin);
    file.Close();
    return true;
}

void GetYields() {
    // Filenames
    std::vector<std::string> filenames = {"BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300to300_Pass_plots.root"
					  , "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500to500_Pass_plots.root"
                                          , "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau300to300_Pass_plots.root"
					  , "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000to2000_Pass_plots.root"
                                          , "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000to3000_Pass_plots.root"
                                         };

    // Output CSV file
    std::ofstream outputFile("output.csv");
    outputFile << "name,content_nominal,error_nominal,content_up,error_up,ratio_up_nominal,content_down,error_down,ratio_down_nominal\n";

    // Iterate over each file
    for (const auto& name : filenames) {
        double content_nom, error_nom, content_up, error_up, content_dn, error_dn;
        std::string path_nom = "nominal/" + name;
        std::string path_up = "up/" + name;
        std::string path_dn = "dn/" + name;

        if (!getHistogramData(path_nom.c_str(), "h_cscRechitClusterSize_FailPass", 2, content_nom, error_nom) ||
            !getHistogramData(path_up.c_str(), "h_cscRechitClusterSize_FailPass", 2, content_up, error_up) ||
            !getHistogramData(path_dn.c_str(), "h_cscRechitClusterSize_FailPass", 2, content_dn, error_dn)) {
            continue;  // Skip this file if any histogram data cannot be retrieved
        }

        double ratio_up = content_up / content_nom;
        double ratio_dn = content_dn / content_nom;

        // Write to CSV
        outputFile << name << "," << content_nom << "," << error_nom << ","
                   << content_up << "," << error_up << "," << ratio_up << ","
                   << content_dn << "," << error_dn << "," << ratio_dn << "\n";
    }

    outputFile.close();
}

