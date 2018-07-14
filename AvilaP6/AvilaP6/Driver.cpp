//Alfonzo Avila		aavila28@cnm.edu	
//Filename: Driver.cpp

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

#include "UserDataStruct.h"
#include "TravelFunctions.h"



int main()
{
	UserData data;
	int sailmonth, sailday, sailyear;
	int bookmonth, bookday, bookyear, days;
	bool validDate, tickWrite;
	string repeat, summary, name, filename;


	header();

	CruiseSpecialDescription();

	do{
		repeat = "n";

		AskforUserSelections(data);

		DetermineBookingDate(&bookmonth, &bookday, &bookyear);

		AskForSailingDate(&sailmonth, &sailday, &sailyear);

		validDate = ValidateSailingDate(sailmonth, sailday, sailyear, bookmonth, bookday, bookyear, &days);

		if (validDate == true)
		{
			summary = CalculateFare(data, sailmonth, sailday, sailyear, bookmonth, bookday, bookyear, days);
			cout << summary;

			name = data.name;

			filename = CreateFileName(name, sailmonth, sailday, sailyear);

			tickWrite = WriteTicket(summary, filename);

			if (tickWrite == true)
			{
				cout << "\nYour receipt was saved as " << filename << ".\n";
			}
		}


		cout << "\nWould you like to purchase another ticket? Enter y or n.	";
		cin >> repeat;
		cin.ignore();


	} while (repeat == "y");


	cout << "\n\nThank you for using the C++ Travel Agency! See you next time!\n";

	return 0;

}