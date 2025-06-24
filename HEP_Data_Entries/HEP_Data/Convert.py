import uproot
import ROOT as rt
import os
import sys
import glob
import pdb

def get_1D_histograms(filename):
    lines1D = [i for i in open(filename, "r").read().split("\n") if "TH1" in i]
    lines2D = [i for i in open(filename, "r").read().split("\n") if "TH2" in i]
    lines = lines1D + lines2D
    histograms = []
    variables = []
    for l in lines:
        histo = l.split(",")[0].strip('"')
        if histo == "": continue
        tmp_string = l.split(" = ")[0]
        if "*" in tmp_string: tmp_string = tmp_string.split("*")[1]
        elif "    " in tmp_string: tmp_string = tmp_string.split("    ")[1]
        print(l.split(" = ")[0], tmp_string)
        histograms.append(histo)
        variables.append(tmp_string)
    return variables, histograms

def get_graphs(filename):
    lines = [i for i in open(filename, "r").read().split("\n") if "TGraph *" in i]
    print(lines)
    histograms = []
    variables = []
    for l in lines:
        graph = l.split("TGraph *")[1].split(" = ")[0]
        if graph == "": continue
        histograms.append(graph)
        variables.append(graph)
    return variables, histograms

if __name__ == "__main__":
    # Copy the files from "plotters"
    # os.system("cp ../../plotters/plotDump/*/* ./paper_plots/")
    os.system("mkdir -p roots")
    base = "paper_plots/"
    filelist = glob.glob(f"{base}*.C")
    print(filelist)
    for f in filelist:
        print(f)
        with open(f, "r") as file:
            filename = f.split(base)[1].split(".C")[0]
            with open(f"./modified_files/{filename}.C", "w") as new_file:
                output_root = f'./roots/{filename}.root'
                prefix = f'TFile * output_root = new TFile("{output_root}", "RECREATE");'
                suffix = ''
                content = file.read()
                variables1D, histograms1D = get_1D_histograms(f)
                variablesGraphs, graphs = get_graphs(f)
                print(variablesGraphs)
                variables = variables1D + variablesGraphs
                for v in variables:
                    suffix += f"\n{v}->Write();"
                print(prefix)
                print(suffix)
                new_file.write("\n".join([prefix, content[0:-3], suffix, "\n}"]))
                new_file.close()
                os.system(f"root -b -q ./modified_files/{filename}.C")

