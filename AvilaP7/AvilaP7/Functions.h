// Alfonzo Avila	aavila28@cnm.edu
//File: Functions.h

void writeheader();
void ReadData(int year[], double TotalRenewableEnergy[], double TotalEnergy[], int total);
void Analysis(int year[], double TotalRenewableEnergy[], double TotalEnergy[], int total, double &grateper, int decades[], double decTotAvgs[], double decReAvgs[],double &RenewTotal, double &ovrTotal);
string WriteAnalysis(int year[], double TotalRenewableEnergy[], double TotalEnergy[], double grateper, int decades[], double decTotAvgs[],double decReAvgs[], double RenewTotal, double ovrTotal);
string WriteFileName();
bool WriteFile(string analysis, string filename);
