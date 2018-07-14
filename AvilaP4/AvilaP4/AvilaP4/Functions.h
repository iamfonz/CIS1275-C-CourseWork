// Alfonzo Avila	aavila28@cnm.edu
// File :  Functions.h

double AskForTemp();

double AskForWindSpeed();

int ValidateInput(double temp, double windspeed);

double calcWindChill(double temp, double windspeed);

double calcFrostbite(double temp, double windspeed);