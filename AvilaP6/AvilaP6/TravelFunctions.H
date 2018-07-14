//Alfonzo Avila		aavila28@cnm.edu
//Filename: TravelFunctions.h

#include <iostream>
#include <string>

using namespace std;

#include "UserDataStruct.h"


void header();

void CruiseSpecialDescription();

void AskforUserSelections(UserData &rdata);

void DetermineBookingDate(int *month, int *day, int *year);

void AskForSailingDate(int *month, int *day, int *year);

bool ValidateSailingDate(int sailmonth, int sailday, int sailyear, int bookmonth, int bookday, int bookyear, int *pday);

string CalculateFare(UserData &data, int sailmon, int sailday, int sailyear, int bookmon, int bookday, int bookyear, int days);

string CreateFileName(string name, int sailmon, int sailday, int sailyear);

bool WriteTicket(string summary, string filename);


