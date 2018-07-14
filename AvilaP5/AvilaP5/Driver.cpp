//Alfonzo Avila	aavila28@cnm.edu
// File : Driver.cpp

#include <iostream>
#include <vector>
#include <string>


using namespace std;

#include "Functions.h"

int main()
{
	vector<string> vShowertype;
	vector<int> vmaxGal;
	vector<int> vminGal;
	vector<int> vrecommendation;
	string repeat, showertype;
	int index, gal;
	bool bvalidatefishshower;
	

	WriteHeader();
	fillvectors(vShowertype, vminGal, vmaxGal);

	do
	{
		repeat = "n";
		askFishShower(vShowertype, &index);
		
		//selection validation
		if (index < 0 || index > 4)
		{
			cout << "\n The selection you've entered is invalid."
				<< "\nWould you like to start over?	y/n?	";
			cin >> repeat;


		}

		else
		{
			calcPond( &gal);

		}
		showertype = vShowertype.at(index);

		bvalidatefishshower = validateFishShower(index, gal, vminGal, vmaxGal, vrecommendation);

		if (bvalidatefishshower == true)
		{
			WriteInfo(vShowertype, gal, index);
		}

		

		else
		{
			WriteInfo(showertype, vShowertype, vrecommendation, gal);

		}


		cout << "\n\nWould you like to start from the beginning again?"
			<< "\n y/n?		";
		cin >> repeat;


	} while (repeat == "y");

	cout << "\n\nThanks for checking out my program! :)\n\n";
	return 0;


}
