#include <iostream>
#include "dayType.h"
using namespace std;

//Static array, stores days of week as reference
string const dayName[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Constructors
dayType::dayType()
{
  setDay(0);
}; //Default constructor, sets day info to Sunday

dayType::dayType(int val)
{
  setDay(val);
}; //One parameter, uses parameter to determine what index to use from dayName

//Class functions

//Precond: integer representing index
//Postcond: defined day variable and associated index (dayNum)
void dayType::setDay(int i)
{
  dayNum = (i % 7);
  day = dayName[dayNum];
}

//Precond: dayType with defined day
//Postcond: prints day
void dayType::printDay()
{
  cout << getDay() << endl;
}

//Precond: dayType with defined day, integer representing days to advance/add
//Postcond: Advances day and dayNum by number of days indicated
void dayType::addDays(int i)
{
  int sum = dayNum + i;
  setDay(sum);
}

//Precond: dayType with defined day
//Postcond: returns day
string dayType::getDay()
{
  return day;
}

//Precond: dayType with defined day
//Postcond: returns the next day
string dayType::getNextDay()
{
  return dayName[(dayNum + 1) % 7];
}

//Precond: dayType with defined day
//Postcond: returns the previous day
string dayType::getPrevDay()
{
  int temp = dayNum + 7;
  return dayName[(temp - 1) % 7];
}