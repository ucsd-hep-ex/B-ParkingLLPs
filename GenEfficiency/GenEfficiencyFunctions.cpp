// GenEfficiencyFunctions.cpp
#include "GenEfficiencyFunctions.h"
#include <iostream>
#include <map>
#include <algorithm>

// Define the DecayEff maps for all samples
using namespace std;

const std::map<int, double> DecayEff_M0p3_300 = {
    {1, 0.000212707}, {3, 0.00367283}, {5, 0.00985236}, {7, 0.0172625}, {10, 0.0291508}, 
    {30, 0.098065}, {50, 0.145035}, {70, 0.17793}, {100, 0.210862}, {300, 0.258932}, 
    {500, 0.241418}, {700, 0.212747}, {1000, 0.154672}, {3000, 0.0245574}, 
    {5000, 0.0140187}, {7000, 0.0109439}, {10000, 0.00906553}
};

const std::map<int, double> DecayEff_M0p3_1000 = {
    {1, 0.000100618}, {3, 0.00254258}, {5, 0.00800441}, {7, 0.0150262}, {10, 0.0266616}, 
    {30, 0.0960547}, {50, 0.143494}, {70, 0.176623}, {100, 0.209753}, {300, 0.257636}, 
    {500, 0.239831}, {700, 0.216861}, {1000, 0.186889}, {3000, 0.0931888}, 
    {5000, 0.0591638}, {7000, 0.0432097}, {10000, 0.0318571}
};

const std::map<int, double> DecayEff_M0p3_3000 = {
    {1, 3.19287e-06}, {3, 0.00115684}, {5, 0.0048204}, {7, 0.0100535}, {10, 0.0195385}, 
    {30, 0.0865576}, {50, 0.135586}, {70, 0.170079}, {100, 0.204531}, {300, 0.254481}, 
    {500, 0.237463}, {700, 0.215004}, {1000, 0.185533}, {3000, 0.094442}, 
    {5000, 0.0628719}, {7000, 0.0456011}, {10000, 0.0300701}
};

const std::map<int, double> DecayEff_M0p5_500 = {
    {1, 3.77367e-06}, {3, 0.000629733}, {5, 0.00289072}, {7, 0.00647825}, {10, 0.0131938}, 
    {30, 0.0614839}, {50, 0.0998057}, {70, 0.129796}, {100, 0.164053}, {300, 0.249964}, 
    {500, 0.257718}, {700, 0.248426}, {1000, 0.228888}, {3000, 0.16045}, 
    {5000, 0.141178}, {7000, 0.132671}, {10000, 0.126259}
};

const std::map<int, double> DecayEff_M0p5_5000 = {
    {1, 3.32679e-08}, {3, 0.000327521}, {5, 0.00226438}, {7, 0.00549864}, {10, 0.0114807}, 
    {30, 0.0572667}, {50, 0.0968001}, {70, 0.12804}, {100, 0.163598}, {300, 0.252375}, 
    {500, 0.260743}, {700, 0.251347}, {1000, 0.230423}, {3000, 0.135273}, 
    {5000, 0.0950152}, {7000, 0.0733655}, {10000, 0.0548025}
};

const std::map<int, double> DecayEff_M1_1000 = {
    {1, 1.58719e-06}, {3, 0.000436579}, {5, 0.00146078}, {7, 0.00281546}, {10, 0.00531544}, 
    {30, 0.0280819}, {50, 0.0518268}, {70, 0.0731419}, {100, 0.100674}, {300, 0.20359}, 
    {500, 0.241852}, {700, 0.255632}, {1000, 0.25756}, {3000, 0.195259}, 
    {5000, 0.158016}, {7000, 0.138829}, {10000, 0.123611}
};

const std::map<int, double> DecayEff_M1_10000 = {
    {1, 3.43275e-10}, {3, 6.0315e-05}, {5, 0.000552854}, {7, 0.00144642}, {10, 0.00322973}, 
    {30, 0.0247581}, {50, 0.0500272}, {70, 0.0725855}, {100, 0.101274}, {300, 0.207775}, 
    {500, 0.247514}, {700, 0.261634}, {1000, 0.263282}, {3000, 0.194883}, 
    {5000, 0.14726}, {7000, 0.117929}, {10000, 0.0907816}
};

const std::map<int, double> DecayEff_M2_2000 = {
    {1, 2.54035e-13}, {3, 2.08154e-06}, {5, 4.82268e-05}, {7, 0.0002002}, {10, 0.000650378}, 
    {30, 0.00906239}, {50, 0.0218598}, {70, 0.0354108}, {100, 0.0548716}, {300, 0.146233}, 
    {500, 0.196283}, {700, 0.225008}, {1000, 0.246836}, {2000, 0.252473}, 
    {3000, 0.232328}, {5000, 0.190787}, {7000, 0.161788}, {10000, 0.135619}
};

const std::map<int, double> DecayEff_M2_10000 = {
    {1, 5.36051e-17}, {3, 4.29226e-07}, {5, 3.50064e-05}, {7, 0.000232487}, {10, 0.000989261}, 
    {30, 0.013645}, {50, 0.0280934}, {70, 0.0412442}, {100, 0.059097}, {300, 0.14649}, 
    {500, 0.196192}, {700, 0.224438}, {1000, 0.245474}, {3000, 0.229871}, 
    {5000, 0.189518}, {7000, 0.159104}, {10000, 0.127579}
};

const std::map<int, double> DecayEff_M3_3000 = {
    {1, 7.72181e-22}, {3, 6.33557e-09}, {5, 1.93e-06}, {7, 2.07529e-05}, {10, 0.000122248}, 
    {30, 0.00386146}, {50, 0.011704}, {70, 0.0212436}, {100, 0.0362698}, {300, 0.117752}, 
    {500, 0.168509}, {700, 0.200698}, {1000, 0.228747}, {3000, 0.239329}, 
    {5000, 0.20582}, {7000, 0.178628}, {10000, 0.151509}
};

const std::map<int, double> DecayEff_M3_10000 = {
    {1, 6.38056e-24}, {3, 1.65837e-09}, {5, 1.27692e-06}, {7, 2.27757e-05}, {10, 0.000196286}, 
    {30, 0.00585752}, {50, 0.0143705}, {70, 0.0240373}, {100, 0.0392737}, {300, 0.122177}, 
    {500, 0.172873}, {700, 0.204767}, {1000, 0.232418}, {3000, 0.241803}, 
    {5000, 0.207522}, {7000, 0.178299}, {10000, 0.146031}
};

// Function to calculate efficiency using linear interpolation
double calculateEfficiency(const std::map<int, double>& decayEffMap, double ctau) {
    auto it = decayEffMap.lower_bound(ctau);
    if (it == decayEffMap.end()) {
        // If ctau is beyond the largest key, return the last value
        return decayEffMap.rbegin()->second;
    }
    if (it == decayEffMap.begin()) {
        // If ctau is before the first key, return the first value
        return it->second;
    }
    // Interpolate between the two nearest points
    auto it1 = it--;
    double x1 = it->first, y1 = it->second;
    double x2 = it1->first, y2 = it1->second;
    return y1 + (ctau - x1) * (y2 - y1) / (x2 - x1);
}

double computeEfficiencyForM0p3_300(double ctau) {
    return calculateEfficiency(DecayEff_M0p3_300, ctau);
}

double computeEfficiencyForM0p3_1000(double ctau) {
    return calculateEfficiency(DecayEff_M0p3_1000, ctau);
}

double computeEfficiencyForM0p3_3000(double ctau) {
    return calculateEfficiency(DecayEff_M0p3_3000, ctau);
}

double computeEfficiencyForM0p5_500(double ctau) {
    return calculateEfficiency(DecayEff_M0p5_500, ctau);
}

double computeEfficiencyForM0p5_5000(double ctau) {
    return calculateEfficiency(DecayEff_M0p5_5000, ctau);
}

double computeEfficiencyForM1_1000(double ctau) {
    return calculateEfficiency(DecayEff_M1_1000, ctau);
}

double computeEfficiencyForM1_10000(double ctau) {
    return calculateEfficiency(DecayEff_M1_10000, ctau);
}

double computeEfficiencyForM2_2000(double ctau) {
    return calculateEfficiency(DecayEff_M2_2000, ctau);
}

double computeEfficiencyForM2_10000(double ctau) {
    return calculateEfficiency(DecayEff_M2_10000, ctau);
}

double computeEfficiencyForM3_3000(double ctau) {
    return calculateEfficiency(DecayEff_M3_3000, ctau);
}

double computeEfficiencyForM3_10000(double ctau) {
    return calculateEfficiency(DecayEff_M3_10000, ctau);
}

// Main function to get efficiency based on sample and ctau
double newGenEfficiency(const std::string& sample, double ctau) {
    if (sample.find("mPhi0p3_ctau300") != std::string::npos) {
        return computeEfficiencyForM0p3_300(ctau);
    }
    if (sample.find("mPhi0p3_ctau1000") != std::string::npos) {
        return computeEfficiencyForM0p3_1000(ctau);
    }
    if (sample.find("mPhi0p3_ctau3000") != std::string::npos) {
        return computeEfficiencyForM0p3_3000(ctau);
    }
    if (sample.find("mPhi0p5_ctau500") != std::string::npos) {
        return computeEfficiencyForM0p5_500(ctau);
    }
    if (sample.find("mPhi0p5_ctau5000") != std::string::npos) {
        return computeEfficiencyForM0p5_5000(ctau);
    }
    if (sample.find("mPhi1p0_ctau1000") != std::string::npos) {
        return computeEfficiencyForM1_1000(ctau);
    }
    if (sample.find("mPhi1p0_ctau10000") != std::string::npos) {
        return computeEfficiencyForM1_10000(ctau);
    }
    if (sample.find("mPhi2p0_ctau2000") != std::string::npos) {
        return computeEfficiencyForM2_2000(ctau);
    }
    if (sample.find("mPhi2p0_ctau10000") != std::string::npos) {
        return computeEfficiencyForM2_10000(ctau);
    }
    if (sample.find("mPhi3p0_ctau3000") != std::string::npos) {
        return computeEfficiencyForM3_3000(ctau);
    }
    if (sample.find("mPhi3p0_ctau10000") != std::string::npos) {
        return computeEfficiencyForM3_10000(ctau);
    }
    // If the sample is not recognized, return a default value or handle the error
    std::cerr << "Warning: Unrecognized sample " << sample << std::endl;
    return 1.0; // Default value or error handling
}
