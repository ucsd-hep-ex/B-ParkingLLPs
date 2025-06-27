import pandas as pd
import os
import glob
import numpy as np
import sys

def get_common(arr1, arr2):
    common = []
    print(arr1)
    print(arr2)
    for i in arr1:
        for j in arr2:
            # name_i = "_".join(i.split("/")[-1].split("_")[0:-2])
            # name_j = "_".join(j.split("/")[-1].split("_")[0:-1])
            name_i = i.split("/")[-1]
            name_j = j.split("/")[-1]
            print(name_i, name_j)
            if name_i == name_j and i not in common: common.append(name_j)
    print(common, len(common))
    return common

if __name__ == "__main__":
    filenames_weighted = glob.glob("not_weighted_cutflow_tables/BToKPhi_MuonLLPDecayGenFilter_*.txt")
    filenames_unweighted = glob.glob("weighted_cutflow_tables/BToKPhi_MuonLLPDecayGenFilter_*.txt")
    
    filenames = get_common(filenames_weighted, filenames_unweighted)
    
    print(filenames)
    split_name = "	No cuts"
    selections = ["Nocuts", "HLT", "nCscRechitClusters>0", "CscPassID"]
    
    for filename in filenames:
        print(filename)
        # filename = filename.split("/")[1]
        table_arr_keys = []
        table_arr_vals = []
        table_arr_eff  = []
        table_arr_cum_eff = []
        table_arr_eff_err = []
        table_arr_cum_eff_err = []
        with open(f"weighted_cutflow_tables/{filename}", "r") as f:
            table = split_name + f.read().split(split_name)[1].split("isMC?:")[0]
            table = table.replace("	", "")
            table_arr = table.split("\n")
            for i, t in enumerate(table_arr):
                if "Dt" not in t and t != "":
                    print(t.replace(" ", "").split(",")[0])
                    table_arr_keys.append(t.replace(" ", "").split(",")[0])
                    table_arr_vals.append(t.replace(" ", "").split(",")[1])
                    cum_eff = float(table_arr_vals[-1]) / float(table_arr_vals[0])
                    cum_eff_err = cum_eff * np.sqrt( (1 / float(table_arr_vals[-1])) + (1 / float(table_arr_vals[0])) )
                    if i != 0:
                        eff = float(table_arr_vals[-1])/float(table_arr_vals[-2])
                        eff_err = eff * np.sqrt( (1 / float(table_arr_vals[-1])) + (1 / float(table_arr_vals[-2])) )
                    else:
                        eff = float(table_arr_vals[-1])/float(table_arr_vals[0])
                        eff_err = eff * np.sqrt( (1 / float(table_arr_vals[-1])) + (1 / float(table_arr_vals[0])) )
                    table_arr_cum_eff.append(f"{cum_eff}")
                    table_arr_eff.append(f"{eff}")
                    table_arr_eff_err.append(f"{eff_err}")
                    table_arr_cum_eff_err.append(f"{cum_eff_err}")
            dataframe = pd.DataFrame({"Selections": table_arr_keys, "N_events": table_arr_vals, "Efficiency": table_arr_eff, "Cum efficiency": table_arr_cum_eff})
        table_arr_keys = []
        table_arr_vals = []
        table_arr_eff  = []
        table_arr_cum_eff = []
        table_arr_eff_err = []
        table_arr_cum_eff_err = []
        with open(f"not_weighted_cutflow_tables/{filename}", "r") as f:
            table = split_name + f.read().split(split_name)[1].split("isMC?:")[0]
            table = table.replace("	", "")
            table_arr = table.split("\n")
            for i, t in enumerate(table_arr):
                if "Dt" not in t and t != "":
                    print(t.replace(" ", "").split(",")[0])
                    table_arr_keys.append(t.replace(" ", "").split(",")[0])
                    table_arr_vals.append(t.replace(" ", "").split(",")[1])
                    cum_eff = float(table_arr_vals[-1]) / float(table_arr_vals[0])
                    cum_eff_err = cum_eff * np.sqrt( (1 / float(table_arr_vals[-1])) + (1 / float(table_arr_vals[0])) )
                    if i != 0:
                        eff = float(table_arr_vals[-1])/float(table_arr_vals[-2])
                        eff_err = eff * np.sqrt( (1 / float(table_arr_vals[-1])) + (1 / float(table_arr_vals[-2])) )
                    else:
                        eff = float(table_arr_vals[-1])/float(table_arr_vals[0])
                        eff_err = eff * np.sqrt( (1 / float(table_arr_vals[-1])) + (1 / float(table_arr_vals[0])) )
                    table_arr_cum_eff.append(f"{cum_eff}")
                    table_arr_eff.append(f"{eff}")
                    table_arr_eff_err.append(f"{eff_err}")
                    table_arr_cum_eff_err.append(f"{cum_eff_err}")
            dataframe_err = pd.DataFrame({"Selections": table_arr_keys, "N_events": np.sqrt(np.array(table_arr_vals).astype(float)), "Efficiency": table_arr_eff_err, "Cum efficiency": table_arr_cum_eff_err})
        print("Efficiencies")
        print(dataframe)
        print()
        print("Errors")
        print(dataframe_err)
        dataframe.to_csv(f"{filename.split('.')[0]}.csv")
        dataframe_err.to_csv(f"{filename.split('.')[0]}_err.csv")
        print()
