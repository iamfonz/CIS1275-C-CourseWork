//Alfonzo Avila		aavila28@cnm.edu
//Filename: TravelFunctions.cpp

#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "UserDataStruct.h"
#include "TravelFunctions.h"




void header()
{
	cout << "Alfonzo Avila	aavila28@cnm.edu\nProgram 6\n"
		<< "\nProgram Objective\n The objective of this program is to book a cruise"
		<< " and calculate\nthe total cost.\n\n";

}

void CruiseSpecialDescription()
{

	cout << "Welcome to the C++ Travel Agency! Today we have a special through the\n"
		<< "C++ Cruise Line sailing to the Western Carribean. The Western round trip\n"
		<< "stops in Labadee (a cruiseline private island); Flamouth, Jamaica; and\n"
		<< "Cozumel, Mexico. The full price is $1769.00 per person. The booking \nspecials"
		<< " are as follows;\n"
		<< "Book 30 days in advance, receive a 60% discount\n"
		<< "Book 60 days in advance, receive a 50% discount\n"
		<< "Book 90 days in advance, receive a 30% discount\n"
		<< "In addition there are excursions available at each stop for the price\n"
		<< "of $225 per person for each excursion.\n";

}



void AskforUserSelections(UserData &rdata)
{

	int dinpref;
	cout << "\nPlease enter your name.	";
	getline(cin, rdata.name);

	cout << "\nPlease enter the number of people saying in the stateroom(max 2). ";
	cin >> rdata.howmany;

	cout << "\nHow many excursions would you like to purchase? (max 6)	";
	cin >> rdata.excursions;


	cout << "\nWould you like and early dinner or late dinner.\n"
		<< "Enter 1 for 6:00PM, or enter 2 for 8:30PM.	";
	cin >> dinpref;


	int table;

	// initialize random seed
	srand(time(NULL));

	// generate random number between 1 and 160: 
	table = rand() % 160 + 1;

	rdata.tablenumber = table;

	if (dinpref == 1)
	{
		rdata.seating = "an early 6:00PM";
	}

	else if (dinpref == 2)
	{
		rdata.seating = "a late 8:30PM";
	}

}

void DetermineBookingDate(int *month, int *day, int *year)
{
	time_t rawtime;
	struct tm ostime;

	time(&rawtime);

	localtime_s(&ostime, &rawtime);

	*month = ostime.tm_mon + 1;
	*day = ostime.tm_mday;
	*year = ostime.tm_year + 1900;


}




void AskForSailingDate(int *month, int *day, int *year)
{
	int m, d, y;
	char slash;
	cout << "\n\nPlease enter your sailing date in the following format;\n"
		<< "MM/DD/YYYY	";

	cin >> m >> slash >> d >> slash >> y;
	cin.ignore();

	*month = m;
	*day = d;
	*year = y;


}

bool ValidateSailingDate(int sailmonth, int sailday, int sailyear, int bookmonth, int bookday, int bookyear, int *pday)
{
	time_t rawtime;
	struct tm sail, book;
	double seconds;
	time(&rawtime);


	sail = *localtime(&rawtime);

	sail.tm_mon = sailmonth - 1;
	sail.tm_mday = sailday;
	sail.tm_year = sailyear - 1900;

	book = *localtime(&rawtime);

	book.tm_mon = bookmonth - 1;
	book.tm_mday = bookday;
	book.tm_year = bookyear - 1900;


	seconds = difftime(mktime(&sail), mktime(&book));


	//converting seconds to days
	double min, hour, day;

	min = seconds / 60;
	hour = min / 60;
	day = hour / 24;

	*pday = day;

	if (seconds < 0)
	{
		cout << "\nThe sail date entered is invalid.";
		return 0;
	}

	else if (day < 7)
	{
		cout << "\nThe sail date entered is less than 7 days away.";
		return 0;
	}

	else
	{
		return 1;
	}



}

string CalculateFare(UserData &data, int sailmon, int sailday, int sailyear, int bookmon, int bookday, int bookyear, int days)
{
	double discountp, fullticket, ticketdiscount, ticket, excursions, total;
	string discountper, ticketWrite, ticketW, excursionW;
	stringstream ss;
	if (days < 30)
	{
		discountp = 0.600;
		discountper = "a 60%";
	}

	else if (days < 60)
	{
		discountp = 0.500;
		discountper = "a 50%";

	}

	else if (days < 90)
	{
		discountp = 0.300;
		discountper = "a 30%";

	}

	else
	{
		discountp = 0;
		discountper = "no";
	}

	fullticket = 1769 * data.howmany;
	ticketdiscount = fullticket * discountp;
	ticket = fullticket - ticketdiscount;
	excursions = 225.00 * data.excursions;
	total = ticket + excursions;

	if (data.howmany > 1)
	{
		ticketW = "tickets";
	}
	else
	{
		ticketW = "ticket";
	}

	if (data.excursions >1)
	{
		excursionW = "excursions";
	}
	else
	{
		excursionW = "excursion";
	}


	ss << "\n\nBooking Date : " << bookmon << "/" << bookday << "/" << bookyear
		<< "\nHello " << data.name << "! Your sail date is on " << sailmon << "/"
		<< sailday << "/" << sailyear << ".\n"
		<< "Your purchase is for " << data.howmany << " "<<ticketW<<" and " 
		<< data.excursions << " excursions\n"
		<< "Because you booked " << days << " days in advance, you receive\n"
		<< discountper << " discount towards your ticket price.\n"
		<< "You have " << data.seating << " dinner reservation at table "
		<< "number " << data.tablenumber << ".\n"
		<< "The price of the " << ticketW << " is $" << setprecision(2) << fixed << ticket << ".\n"
		<< "The price of the " << excursionW << " is $" << setprecision(2) << fixed << excursions
		<< ".\nThe total price of your purchase is $" << setprecision(2) << fixed << total
		<< ".\nWe look forward to having you as our C++ Cruise Line guest!\n";

	ticketWrite = ss.str();

	return ticketWrite;

}

string CreateFileName(string name, int sailmon, int sailday, int sailyear)
{
	stringstream ss;
	string filename;

	ss << name << "_" << sailmon << "_" << sailday << "_" << sailyear << ".txt";

	filename = ss.str();
	return filename;

}

bool WriteTicket(string summary, string filename)
{
	ofstream output;
	output.open(filename);
	if (!output)
	{
		cout << "The file did not open.";
		return 0;
	}

	output << summary;
	output.close();
	return 1;



}


