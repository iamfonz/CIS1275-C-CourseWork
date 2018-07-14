# P3 Travel Agency

The C++ Travel Agency has a website that allows its customers to book Cruises on-line for exceptionally low fares only on the C++ Cruise Line.  All staterooms are OceanView and the same low price.   There is a current special on cruises to the Caribbean, specificially, to the Western Caribbean.  The cruises depart regularly from Fort Lauderdale, Florida and last 7 days.  

The Western Round-trip itinerary stops in 1)Labadee (a Cruiseline Private Island) 2)Falmouth, Jamaica, and  3) Cozumel, Mexico with 3 days at sea.  The full price per person  is $1769.00 for the Western Route. Here is the special: 
   - If you book your cruise less than 30 days in advance, the discount is 60%
   - If you book less than 60 days in advance, the discount is 50%.
   - If you book less than 90 days in advance, the discount is 30%. 

In addition, there are excursions  available for purchase for each port.  These are guided tours or activities specific to the location.  They cost $225.00 each per person.

In main, begin by presenting your header using your ```Header``` function, which includes a brief description of the program. Present the information about the cruises and the discounts available using the ```CruiseSpecialDescription``` function.

Declare variables and a ```UserData```  struct variable, ```UserData data```. ```UserData``` contains the variables for reservation name, which cruise is chosen, how many people and how  many excursions.

The definition of the UserData struct should be found in the UserDataStruct.h file, and should look like this:

```C++
struct UserData
{
	string name;		//reservation name	
	int howMany;		//how many in the stateroom (1 or 2)
	int excursions;	//how many excursions purchased
	int tableNumber;	//table assigned for dinner 1-160
	string seating;	//6:00pm early seating, 8:30 pm late seating
};
```

After you show your header and cruise description, begin a do-while or while loop to allow the user to purchase multiple cruise tickets.

Call the ```AskForUserSelections``` to ask the user for:
   - the reservation name
   - how many people in the stateroom (max is 2)
   - how many excursions are to be purchased (total number, ie if there are 2 people and one  wants 2 excursions and the other wants 1 excursion, then 3 excursions are purchased)
   - ask if the user wants early dinner seating or late. (6:00 pm or 8:30 pm)

Call ```AskForSailingDate``` to ask the user for the ints representing the  month, day, and year of the sailing date. They are passed by pointers.  The function return is void.

Call ```DetermineBookingDate```, which obtains today’s date  in integers by using the System date struct.  They are passed by pointers.  The function return is void.

The next step is to validate the sailing date entered by the user.  Call the function ```ValidateSailingDate```, which will return a ```bool```, indicating whether the sailing date is valid.  The arguments to the function will be the three integers for the booking date and the three integers for the sailing date.  Check to make sure that the user has entered a “proper” date – that it is not the 31st of February, or the -2nd of July.  If the sailing  date is valid, check that the sailing date is not sooner than the booking date or less than 1 week after the booking date. If the date is invalid, tell the user, and then ask if the user wishes to book another cruise. **DO NOT** trap them in a condition where they must enter valid dates. 

In main, check the bool return and if the date entered is valid, call ```CalculateFare```, which will be passed the struct variable, data,  the sailing date integers and the booking date integers.  The function returns a nicely formatted string, created with ```stringstream```, which describes all of the cruise information in the form of a Cruise ticket or receipt

In main, display the nicely formatted string.  Call the function ```CreateFilename```, which returns a string (the filename) and is passed the reservation name and the sailing date integers.   ```CreateFilename``` uses ```stringstream``` to build a filename using these elements:  ```reservationName_sailingMonth_sailingDay_sailingYear.txt```. 

Finally, call ```WriteTicket```, which is passed the formatted string and the filename and returns a ```bool``` to indicate whether the file was opened and written.  ```WriteTicket``` opens a new file , checks to be sure the file is open.  If it is open, it writes the formatted string into the file, closes the file and returns ```true```.  If the file did not open, it returns ```false```.

Main then checks the bool return.  If the file was opened and written, display to the user the filename of the Cruise Ticket, If not, report that to the user, too.

Ask the user if he/she wants to purchase another ticket.  If not, display a good-bye message.

All monetary amounts should be displayed using $ and 2 decimal places.

| Return Type| Function Name|Arguments|
| ------------- |:-------------:| -----:|
| **void**     | _Header_ | ```()``` |
| **void**       | _CruiseSpecialDescription_|```()```|
| **void** | _AskForUserSelection_| ```(UserData& data)``` |
| **void** | _DetermineBookingDate_|    ```( int* month, int* day, int* year)``` |
| **void** | _AskForSailingDate_| ```( int* month, int* day, int* year)```|
| **bool** | _ValidateSailingDate_|```(int monSail, int daySail, int yrSail, int monBook, int dayBook, int yrBook)``` |
| **string** | _CalculateFare_|```(UserData&  data, int monSail, int daySail, int yrSail, int monBook, int dayBook, int yrBook)```  |
| **string** | _CreateFileName_|```( string name, int monSail, int daySail, int yrSail)```  |
| **bool** | _WriteTicket_|```(string summary, string filename)```  |
| **bool** | _IsItLeapYear_|```(int year)```  |
