# CIS1275-P4 - Windchill And Functions

### Program Requirements 
#### (From the assignment document)

This program calculates the Windchill Temperature based on the NOAA.gov formula shown below.  The Windchill Temperature provides an accurate way to calculate the dangers from winter winds and freezing temperatures. Here is their chart showing the wind versus temperature. <http://www.nws.noaa.gov/om/windchill/>
NOTE that the wind chill can only be calculated if the wind is blowing 5 mph or faster and the temperature must be 40 degrees or colder. These are empirical equations and have ranges of validity.

![alt text](https://s20.postimg.cc/9nvazoe7h/windchill.jpg "Windchill Chart")

The Time to frostbite is calculated using another NOAA formula. 
 Ft = ((-24.5 x ((0.667 x (V x 8/5)) + 4.8)) + 2111) x (-4.8 - ((T - 32) x 5/9)) -1.668
There is also a range of values for Time to Frostbite that produce invalid calculations.  Check your values using logic.  For instance, if Time to Frostbite evaluates to a negative number, that can’t be a valid range.  
and then use the limits of that range in your program to check your calculation.  

The program will first show your class header and then begin a do while loop. In this loop the program calls functions to ask the user to enter the temperature, and then enter the wind speed. Main then calls the validateTempWS function, which returns an integer.  If the values are not within valid range, **_then report which value_** is out of range.  Do not call the functions to calculate Wind Chill and Time to Frostbite.  Drop to the “do another” question.

**_Only_** if the temperature and wind speed are within the valid range, that is, the wind speed >=5 mph and the temperature <= 40, the program will then call the functions to calculate the wind chill temperature and frostbite time. The results of those calculations should be written in a neatly formatted sentence. Here are two examples: 


```If the temp is –5 deg F and the wind is blowing 15 mph, 
it feels like –26 degrees and you can experience frostbite in 16 minutes.

If the temp is 25 deg F and the wind is blowing 30 mph, 
it feels like 8 degrees but there is no immediate threat of frostbite.
```

Then ask the user if he/she wants to do more Windchill/Time to frostbite calculations. Do not trap your user in a loop that forces him to enter correct data.  Continue to allow the user to calculate Windchill/Time to frostbite until he/she says no more. Then say Good-bye.

#### Windchill Program Design
This program will be built using functions that you write. In the table below, the function prototypes and description is presented. You must follow these prototypes.

| Function        | Description           |
| ------------- |:-------------:|
| ```double AskForTemperature( )```    | asks the user to enter a temperature, returns this value, does no error checking  |
| ```double  AskForWindSpeed( )```      | asks the user to enter a wind speed in MPH, returns this value, does no error checking      |
| ```int ValidateTempWS(double temp, double windsp)``` | is passed the temperature and windspeed.  Determines if values are within valid range.  Returns an integer value which indicates correctness of values.  For example you validation codes might look like this, 0 = all OK, 1 = both invalid, 2 = temp invalid, 3 = wind invalid.  You may use your own numbering scheme, but it must be integer-based.       |
| ```double CalcWindchill(double temp, double windsp)```      | is passed the temperature and windspeed. Should only be called if values are within valid range      |
| ```int DetermineFrostbiteTimes( double temp, double windsp)```      | is passed in the valid temperature and windsp and calculates the applicable frostbite time.      |


All functions are called from main.  Main writes out results.  All double values are displayed to two decimal values of accuracy.

Be sure that your source code documents the validation codes!!!
