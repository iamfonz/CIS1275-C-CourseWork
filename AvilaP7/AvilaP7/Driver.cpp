// Alfonzo Avila	aavila28@cnm.edu	
// File: Driver.cpp

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
#include "Functions.h"

int main()
{
	//Declaring variables to store data from file-AA
	int year[66], total =66;
	double TotalRenewableEnergy[66];
	double TotalEnergyProd[66];

	//Decaring variables to store analysis data -AA
	int decades[6];
	double decReAvgs[6], decTotAvgs[6];
	double grateper, renewTotal, ovrTotal;
	bool write;

	string analysis, filename;

	writeheader();


	ReadData(year, TotalRenewableEnergy, TotalEnergyProd, total);

	Analysis(year, TotalRenewableEnergy, TotalEnergyProd, total, grateper, decades, decTotAvgs,decReAvgs, renewTotal, ovrTotal);


	analysis = WriteAnalysis(year, TotalRenewableEnergy, TotalEnergyProd, grateper, decades, decTotAvgs, decReAvgs,renewTotal, ovrTotal);

	filename = WriteFileName();

	write = WriteFile(analysis, filename);

	if (write == 0)
	{
		return 0;

	}

	else
	{
		cout << "\nThe file has been successfully writen.\n";
	}

	cout << "\nThanks for checking out my program and teaching me this"
		<< " exciting coding!!\n\n";

	return 0;


}