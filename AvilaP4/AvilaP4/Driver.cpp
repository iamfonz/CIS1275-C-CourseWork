// Alfonzo Avila	aavila28@cnm.edu
// File :  Driver.cpp

#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

int main()
{
	cout << "Alfonzo Avila\nProgram 4: Windchill and Frostbite times.\n"
	<< "\nThe objective of this program is to calculate windchill and frostbite times\n"
		<< "based on user input values for temperature and windspeed.\n\n";
	string repeat;
	double temp, windspeed, windchill, frostbite;
	int validationCode;

	do
	{
		repeat = "n";
		validationCode = 0;
	
		temp = AskForTemp();


		windspeed = AskForWindSpeed();

		validationCode = ValidateInput(temp, windspeed);

		//Validation code 0= both inputs valid
		//ValidationCode 1= windspeed invalid
		//validationCode 2= temp invalid
		//ValidationCode 3= both invalid
		if (validationCode == 1)
		{
			cout << "\nThe windspeed entered is invalid.\n";
			goto doAnother;

		}
		else if (validationCode == 2)
		{ 
			cout << "\nThe temperature is invalid.\n";
			goto doAnother;
		}

		else if (validationCode == 3)
		{
			cout << "\nBoth values are invalid.\n";
				goto doAnother; 
		}


		windchill = calcWindChill(temp, windspeed);

		frostbite = calcFrostbite(temp, windspeed);

		cout << "\n\nWith an outside temperature of " << temp <<
			" degrees farenheit and a windspeed of \n" << windspeed
			<< " MPH, the wind chill temperature would be " << round(windchill)
			<< " degrees farenheit.\n";

		if (frostbite > 0)
		{
			cout << "One would experience frostbite in approximately "
				<< round(frostbite) << " minutes.\n";
		}

		else
		{
			cout << "There would be no immediate frostbite threat.\n";
		}

	doAnother:
		cout << "\nWould you like to try another temperature and windspeed?\n"
			<< "y/n ==>	";
		cin >> repeat;

	} while (repeat == "y");

	cout << "\n\nThanks for calculation. See ya next time! ;)\n\n";

	return 0;

}

