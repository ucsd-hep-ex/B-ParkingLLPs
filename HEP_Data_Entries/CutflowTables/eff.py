import uproot
import numpy as np

def analyze_histogram(root_file_path_contents, root_file_path_errors, hist_name):
    ratios = []
    ratio_errors = []

    with uproot.open(root_file_path_contents) as file:
        hist = file[hist_name]
        contents = hist.values()[1::]

    with uproot.open(root_file_path_errors) as file:
        hist = file[hist_name]
        contents_uw = hist.values()[1::]
        errors_uw = hist.errors()[1::]
        print(contents, contents_uw, errors_uw)

    for i in range(len(contents)):
        if (i != 0):
            prev = contents[i-1]
            curr = contents[i]
            prev_uw = contents_uw[i-1]
            curr_uw = contents_uw[i]
            prev_err_uw = errors_uw[i-1]
            curr_err_uw = errors_uw[i]
        else:
            prev = contents[0]
            curr = contents[i]
            prev_uw = contents_uw[0]
            curr_uw = contents_uw[i]
            prev_err_uw = errors_uw[0]
            curr_err_uw = errors_uw[i]

        if prev == 0:
            ratios.append(np.nan)
            ratio_errors.append(np.nan)
            continue

        ratio = curr / prev
        
        ratio_uw = curr_uw / prev_uw
        rel_error = np.sqrt((curr_err_uw / curr_uw)**2 + (prev_err_uw / prev_uw)**2) if curr_uw != 0 else (prev_err_uw / prev_uw)
        error_ratio = ratio_uw * rel_error

        ratios.append(ratio)
        ratio_errors.append(error_ratio)

    return np.array(ratios), np.array(ratio_errors)

if __name__ == "__main__":
    
    root_file_path_contents = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000_ext2to300_nominal_plots.root"
    root_file_path_errors = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi1p0_ctau1000_ext2to300_nominal_plots.root"
    
    root_file_path_contents = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000_ext2to700_nominal_plots.root"
    root_file_path_errors = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi2p0_ctau2000_ext2to700_nominal_plots.root"
    
    root_file_path_contents = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000_ext2to700_nominal_plots.root"
    root_file_path_errors = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi3p0_ctau3000_ext2to700_nominal_plots.root"
    
    root_file_path_contents = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300_ext2to70_nominal_plots.root"
    root_file_path_errors = "BToKPhi_MuonLLPDecayGenFilter_PhiToPi0Pi0_mPhi0p3_ctau300_ext2to70_nominal_plots.root"
    
    filelist = [
        "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi1p0_ctau1000_ext2to300_nominal_plots.root",
        "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi2p0_ctau2000_ext2to700_nominal_plots.root",
        "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi3p0_ctau3000_ext2to700_nominal_plots.root",
        "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p3_ctau300to70_nominal_plots.root",
        "BToKPhi_MuonLLPDecayGenFilter_PhiToPiPlusPiMinus_mPhi0p5_ctau500_ext2to100_nominal_plots.root",
    ]
    
    for file in filelist:
        print(file)
        root_file_path_contents = file
        root_file_path_errors = file
        
        histogram_name = "cutflow_histogram"
        ratios, errors = analyze_histogram(root_file_path_contents, root_file_path_errors, histogram_name)

        for i, (r, e) in enumerate(zip(ratios, errors), start=1):
            if i != 2 and i != 3 and i != 4 and i != 15: continue;
            print(f"Bin {i}/{i+1}: Ratio = {r}, Error = {e}")
        print()
