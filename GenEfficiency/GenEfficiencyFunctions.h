#ifndef GENEFFICIENCYFUNCTIONS_H
#define GENEFFICIENCYFUNCTIONS_H

#include <string>
#include <map>

// Function to calculate efficiency using linear interpolation
double calculateEfficiency(const std::map<int, double>& decayEffMap, double ctau);

// Function declarations for each sample
double computeEfficiencyForM0p3_300(double ctau);
double computeEfficiencyForM0p3_1000(double ctau);
double computeEfficiencyForM0p3_3000(double ctau);
double computeEfficiencyForM0p5_500(double ctau);
double computeEfficiencyForM0p5_5000(double ctau);
double computeEfficiencyForM1_1000(double ctau);
double computeEfficiencyForM1_10000(double ctau);
double computeEfficiencyForM2_2000(double ctau);
double computeEfficiencyForM2_10000(double ctau);
double computeEfficiencyForM3_3000(double ctau);
double computeEfficiencyForM3_10000(double ctau);

// Main function to get efficiency based on sample and ctau
double newGenEfficiency(const std::string& sample, double ctau);

#endif // GENEFFICIENCYFUNCTIONS_H
