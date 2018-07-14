// Alfonzo Avila	aavila28@cnm.edu
// File :  Functions.cpp

#include <iostream>
#include <math.h>
#include "Functions.h"

using namespace std;


double AskForTemp()
{
	double temp;
	cout << "\nPlease enter the temperature in degrees Farenheit.\n"
		<< "Note: The temperature must be 40 degrees Farenheit or below\n"
		<< "for windchill to occur.	";
	cin >> temp;
	return temp;
		
}

double AskForWindSpeed()
{

	double windspeed;
	cout << "\nPlease enter the windspeed in miles per hour."
		<< "\nNote: The windspeed must be 5 MPH or faster for \n"
		<< "windchill to occur.	";
	cin >> windspeed;

	return windspeed;
}

int ValidateInput(double temp, double windspeed)
{


	if (temp > 40 && windspeed < 5)
	{
		return 3;
	}

	else if (temp <= 40 && windspeed < 5)
	{
		return 1;

	}

	else if (temp > 40 && windspeed >= 5)
	{
		return 2;

	}


	return 0;
}

double calcWindChill (double temp, double windspeed)
{
	double vpow, piece1, piece3, piece2, final;

	vpow = pow(windspeed, 0.16);
	piece1 = 35.74 + 0.6215 * temp;
	piece2 = 35.75 * vpow;
	piece3 = 0.4275 * temp * vpow;
	final = piece1 - piece2 + piece3;
	return final;
}

double calcFrostbite(double temp, double windspeed)
{
	double piece1Inner, t_32, piece1entirety, piece2, piece2pow, final;

	piece1Inner = 0.667 * windspeed * (8.0 / 5.0) + 4.8;
	piece1entirety = -24.5 * piece1Inner + 2111;
	t_32 = temp - 32;
	piece2 = -4.8 - t_32 * (5.0 / 8.0);
	piece2pow = pow(piece2, -1.668);
	final = piece1entirety * piece2pow;
	return final;

}