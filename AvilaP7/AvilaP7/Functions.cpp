// Alfonzo Avila	aavila28@cnm.edu
// File: Functions.cpp

#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
#include <iomanip>


using namespace std;
#include "Functions.h"


void writeheader()
{

	cout << "\nAlfonzo Avila	aavila28@cnm.edu\n"
		<<"Program 7 : Data Analysis\n"
		<<"\n *Program Objective*"
		<<"\nThe objective of this program is to read in data from a data file and\n"
		<<"perform an analysis. The data file was obtained from www.eia.gov which\n" 
		<<"is the website of the U.S. Energy Information Administration. The data contains\n"
		<<"the primary energy production by source beginning from 1949 to 2014.\n"
		<<"The only pieces of data being analyzed are the total renewable energy\n"
		<<"production and the overall total energy production.The analysis is \n"
		<<"saved as a text file with a name typed in by the user.\n\n";

}




void ReadData(int year[], double TotalRenewableEnergy[], double TotalEnergy[], int total)
{
	string line;

	ifstream input;
	input.open("EnergyData.txt");
	if (!input)
	{
		cout << "\nNo file found!\n";
		exit(1);

	}

	//skip the first 12 lines of data file -Fonz

	for (int i = 0; i < 12; ++i)
	{

		getline(input, line);

	}

	//starts reading in data -fonz
	int j = 0;
	do
	{
		double temp;
		int dyear;
		double drenew;
		double dtotal;

		input >> dyear >> temp >> temp >> temp >> temp >> temp
			>> temp >> temp >> temp >> temp >> temp >> temp >> drenew >> dtotal;

		year[j] = dyear;
		TotalRenewableEnergy[j] = drenew;
		TotalEnergy[j] = dtotal;

		++j;


	} while (j < total);


}

void Analysis(int year[], double TotalRenewableEnergy[], double TotalEnergy[], int total, double &grateper, int decades[], double decTotAvgs[], double decReAvgs[], double &RenewTotal, double &ovrTotal)
{
	/*calculate percent growth of renewable energy produced
	from 1949-2014 */

	double grate, diff;
	string growthAnalysis;
	stringstream sgrowthanalysis;


	diff = TotalRenewableEnergy[65] - TotalRenewableEnergy[0];

	grate = diff / TotalRenewableEnergy[0];

	grateper = grate *100.00;

	/*calculate total energies produced from 1949-2014 both renewable
	and total energy. A summation equation is used */

	//intializing summation at 0
	double rtotal = 0.0, ototal = 0.0;

	for (int i = 0; i < total; ++i)
	{
		rtotal += TotalRenewableEnergy[i];
		ototal += TotalEnergy[i];


	}

	RenewTotal = rtotal;
	ovrTotal = ototal;

	/*begin filling decade arrays */

	decades[0] = 50;
	decades[1] = 60;
	decades[2] = 70;
	decades[3] = 80;
	decades[4] = 90;
	decades[5] = 2000;

	/*begin calculating averages for each decade*/
	double refifties = 0.0, totfifties = 0.0;
	for (int j = 1; j < 11; ++j)
	{
		refifties += TotalRenewableEnergy[j];
		totfifties += TotalEnergy[j];
	}

	refifties /= 10;
	totfifties /= 10;
	decReAvgs[0] = refifties;
	decTotAvgs[0] = totfifties;

	double resixties = 0.0, totsixties = 0.0;
	for (int j=11 ; j < 21; ++j)
	{
		resixties += TotalRenewableEnergy[j];
		totsixties += TotalEnergy[j];


	}

	resixties /= 10;
	totsixties /= 10;
	decReAvgs[1] = resixties;
	decTotAvgs[1] = totsixties;

	double reseventies = 0.0, totseventies = 0.0;
	for (int j = 21; j < 31; ++j)
	{
		reseventies += TotalRenewableEnergy[j];
		totseventies += TotalEnergy[j];

	}
	reseventies /= 10;
	totseventies /= 10;
	decReAvgs[2] = reseventies;
	decTotAvgs[2] = totseventies;


	double reeighties = 0.0, toteighties = 0.0;

	for (int j = 31; j < 41; ++j)
	{
		reeighties += TotalRenewableEnergy[j];
		toteighties += TotalEnergy[j];

	}

	reeighties /= 10;
	toteighties /= 10;

	decReAvgs[3] = reeighties;
	decTotAvgs[3] = toteighties;

	double renineties = 0.0, totnineties = 0.0;
	for (int j = 41; j < 51; ++j)
	{
		renineties += TotalRenewableEnergy[j];
		totnineties += TotalEnergy[j];

	}

	renineties /= 10;
	totnineties /= 10;

	decReAvgs[4] = renineties;
	decTotAvgs[4] = totnineties;

	double rethousands = 0.0, totthousands = 0.0;

	for (int j = 51; j < 61; ++j)

	{
		rethousands += TotalRenewableEnergy[j];
		totthousands += TotalEnergy[j];
	}

	rethousands /= 10;
	totthousands /= 10;

	decReAvgs[5] = rethousands;
	decTotAvgs[5] = totthousands;




}

string WriteAnalysis(int year[], double TotalRenewableEnergy[], double TotalEnergy[], double grateper, int decades[], double decTotAvgs[], double decReAvgs[],double RenewTotal, double ovrTotal)
{
	stringstream sintro, sgrowthanalysis, senergytotals, sdecades, ss;
	string TotalAnalysis, growthAnalysis, energytotals,decade, intro;

	sintro << "Alfonzo Avila\n\n"
		<< "Energy Production Analysis\n\n"
		<< "*Introduction*\n"
		<< "The data file was obtained from the U.S. Energy Information Administration.\n"
		<< "The data contains the primary energy production by source beginning from\n"
		<<"1949 to 2014 in quadrillion BTU (British thermal unit).The only pieces of \n"
		<< "data being analyzed are the total renewable energy production and the\n"
		<< "overall total energy production. Renewable energy production is energy\n"
		<< "sourced from hydroelectric power, geothermal, solar/photovoltaic, wind and\n"
		<< "biomass. Below is the URL address of the data source.\n"
		<< "\nhttp://www.eia.gov/totalenergy/data/monthly/#summary\n\n";

	intro = sintro.str();

	sgrowthanalysis <<"\n\n*Data Analysis Question #1*\n"
		<< "How much has renewable energy production grown since 1949?\n"
		<< "\nIn " << year[0] << ", " << setprecision(2)<<fixed <<TotalRenewableEnergy[0] 
		<< " quadrillion BTUs (British thermal unit) of renewable energy\n"
		<<"was produced in the U.S. It's important to note that certain renewable\n"
		<<"energy was not available yet such as geothermal, solar, and wind energy.\n"
		<<"As of 2014, renewable energy production grew " << setprecision(1)
		<< fixed<< grateper << "% since 1949.\n";



	growthAnalysis = sgrowthanalysis.str();

	senergytotals << "\n\n*Data Analysis Question #2*"
		<< "\nHow much renewable and overall total energy has been produced since 1949?\n"
		<< "\nTotal Renewable Energy Produced(1949-2014)	" <<setprecision(0)<<fixed
		<< RenewTotal << " quadrillion BTU"
		<< "\nTotal Overall Energy Produced(1949-2014)	" << setprecision(0)<<fixed
		<<ovrTotal << " quadrillion BTU\n";

	energytotals = senergytotals.str();
	 
	sdecades << "\n\n*Data Analysis Question #3*\n"
		<<"What are the decade averages for both renewable energy produced\n"
		<<"and total overall energy produced?\n"

		<< "\nDecade		Average Renewable	Average Overall\n"
		<< "		Energy			Energy\n";

	for (int i = 0; i < 6; ++i)
	{
		sdecades << setprecision(2)<<fixed<<decades[i] << "'s		"
			<<setprecision(2)<<fixed<<decReAvgs[i]<<"			"
			<<setprecision(2)<<fixed<< decTotAvgs[i] << endl;

	}
	sdecades << "The averages are in quadrillion BTU (British thermal unit).\n";


	decade = sdecades.str();
	ss << intro << growthAnalysis << energytotals<< decade;


		TotalAnalysis = ss.str();

	return TotalAnalysis;

}

string WriteFileName()
{
	string filename;

	cout << "\nPlease enter the file name for the report. =>	";
	cin >> filename;

	return filename;


}

bool WriteFile(string analysis, string filename)
{
	ofstream output;
	output.open(filename);
	if (!output)
	{
		cout << "The file did not open.";
		return 0;
	}

	output << analysis;
	output.close();
	return 1;



}
