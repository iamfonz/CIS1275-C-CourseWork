//Alfonzo Avila	aavila28@cnm.edu
// File : Functions.cpp

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#include "Functions.h"

void WriteHeader()
{
	cout << "\nAlfonzo Avila\nProgram 5\n\n"
		<< "The objective of this program is to display a menu of pond showers\n"
		<< "for the user to select. The user will enter their pond dimensions\n"
		<< "and based on the dimensions, the program will validate the selection.\n"
		<< "If the user selection isn't ideal for their pond, one will be recommended.\n\n";


}

void fillvectors(vector<string> &vShowerType, vector<int> &vminGal, vector<int> &vmaxGal)
{
	vShowerType.push_back("Shebunkin Shower");
	vminGal.push_back(200);
	vmaxGal.push_back(400);

	vShowerType.push_back("Koi Rainhead");
	vminGal.push_back(300);
	vmaxGal.push_back(500);

	vShowerType.push_back("Crescent Drizzle");
	vminGal.push_back(400);
	vmaxGal.push_back(1000);

	vShowerType.push_back("Stoneroller Deluge");
	vminGal.push_back(900);
	vmaxGal.push_back(5000);

	vShowerType.push_back("Megalotis Pour");
	vminGal.push_back(3000);
	vmaxGal.push_back(10000);

}

void askFishShower(vector<string> &vShowerType, int *pindex)
{
	cout << "\nSelect a shower from the choices below.\n";
		
	for (int i = 0; i < vShowerType.size(); ++i)
	{
		cout << i << "	" << vShowerType.at(i) << endl;
	}
	cout << "\nEnter your selection. ";
	cin >> *pindex;
}

void calcPond(int *gal)
{
	int type, radius, height, length, width, volume;
	double rSquared;

	cout << "\nLet's determine how many gallons are in your pond."
		<< "\n\nFirst of all, is your pond round or rectangular?"
		<< "\nEnter 0 for round and 1 for rectangular.	";
	cin >> type;

	//volumeOfaCylinder = pi * radius^2 * height
	//volumeOfaRectangle = length*width*height
	// 1 US gallon = 231 cubic inches

	if (type == 0)
	{
		cout << "\n\nEnter the radius in inches.	";
		cin >> radius;

		cout << "\n\nEnter the depth(height) in inches.	";
		cin >> height;
		rSquared = pow(radius, 2);
		volume = 3.14159265359 * rSquared * height;
		*gal = volume / 231;
	}

	else if (type == 1)
	{
		cout << "\n\nEnter the length in inches. ";
		cin >> length;

		cout << "\n\nEnter the width in inches. ";
		cin >> width;

		cout << "\n\nEnter the height in inches. ";
		cin >> height;

		volume = length * width * height;
		*gal = volume / 231;

	}
	else
	{
		cout << "The selection you entered is invalid.";
	
	}


}

bool validateFishShower(int index, int gal, vector<int> &vminGal, vector<int> &vmaxGal, vector<int> &vrecommendation)
{
	


	if (gal >= vminGal.at(index) && gal <= vmaxGal.at(index))
	{
		return 1;
	}



	else
	{
		for (int recommendation = 0; recommendation < vminGal.size(); ++recommendation)
		{
			if (gal >= vminGal.at(recommendation) && gal <= vmaxGal.at(recommendation))
				{
					vrecommendation.push_back(recommendation);
				}
			
		
		}
		return 0;
	
	}

}

void WriteInfo(vector<string> &vshowertype, int gal, int index)
{
	cout << "\n\nThe " << vshowertype.at(index) << " will work great for your "
		<< gal << " gallon pond.";

}


void WriteInfo(string showertype, vector<string> &vShowerType, vector<int> &vrecommendation, int gal)
{
	

	cout << "\n\n The " << showertype << " is not suitable for your " << gal << " "
		<< " gallon pond.";

	if (gal < 200)
	{
		cout << "\nUnfortunately your pond is too small for a shower.";

	}

	else
	{
		cout << "\nBelow are recommended showers for your pond.\n";
		for (int i = 0; i < vrecommendation.size(); ++i)
		{
			cout << vShowerType.at(vrecommendation.at(i)) << endl;
		}
	}

}