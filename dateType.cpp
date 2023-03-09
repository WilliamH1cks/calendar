#include <iostream>
#include "dateType.h"
using namespace std;

//Integer array used to determine maximum value of day. Doesn't account for leap years.
int const days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//Constructors
dateType::dateType()
{
  setDate(1, 1, 1900);
}; //Default constructor, sets date to 1/1/1900

dateType::dateType(int m, int d, int yr)
{
  setDate(m, d, yr);
}; //Three parameters, uses parameters to create date

//Class functions

//Precond: An integer
//Postcond: The year variable initialized
void dateType::setYear(int yr)
{
  if (yr < 1900)
  {
    cout << "Error: Year must be at the earliest 1900. Returining to default value of 1900...";
    yr = 1900;
    };
  year = yr;

  if (!isLeapYear(getYear()) && getMonth() == 2 && getDay() == 29)
  {
    cout << endl << "Error: Non-leap year (\"common year\") cannot have Feb. 29 as a date. Resetting date to Feb. 1..." << endl;
    setDay(1);
  }
}

//Precond: An integer
//Postcond: The month variable initialized
void dateType::setMonth(int m)
{
  if (m < 1 || m > 12)
  {
    cout << endl << "Error: Month was not between 1 and 12, inclusive. Returning to default value of 1..." << endl;
    m = 1;
  };
  month = m;
}

//Precond: An integer
//Postcond: The day variable initialized
void dateType::setDay(int d)
{
  if (d < 1)
  {
    cout << endl << "Error: Value too small. Resseting to default value (1)..." << endl;
    d = 1;
  }
  if (d > numDaysInMonth())
  {
    cout << endl <<  "Error: Value too large. Resetting to default value (1)..." << endl;
    d = 1;
  }
  day = d;
}

//Precond: Three integers
//Postcond: A date is created
void dateType::setDate(int m, int d, int yr)
{
  setYear(yr);
  setMonth(m);
  setDay(d);
}

//Precond: The date is initiated
//Postcond: Returns the year
int dateType::getYear()
{
  return year;
}

//Precond: The date is initialized
//Postcond: Returns the month
int dateType::getMonth()
{
  return month;
}

//Precond: The date is initialized
//Postcond: Returns the day
int dateType::getDay()
{
  return day;
}

//Precond: The year is initialized
//Postcond: Returns whether the given year is a leap year
bool dateType::isLeapYear(int yr)
{
  if (yr % 4 == 0 && (yr % 400 == 0 || yr % 100 != 0 ))
    return true;
  else return false;
}

//Precond: The month is initialized
//Postcond: The number of the days in the current month is returned
int dateType::numDaysInMonth()
{
  if (isLeapYear(getYear()) && month == 2)
    return 29;
  return days[getMonth() - 1];
}

//Precond: The year is initialized
//Postcond: The number of days in the current year is returned
int dateType::numDaysInYear()
{
  if (isLeapYear(getYear()))
    return 366;
  else return 365;
}


//Precond: Month and Year are initialized
//Postcond: The number of days for the month and overall year are printed
void dateType::printNumDays()
{
  cout << "Number of days in current month: " << numDaysInMonth() << endl;
  cout << "Number of days in current year: " << numDaysInYear() << endl;
}


//Precond: The date is initialized
//Postcond: The date is printed
void dateType::printDate()
{
  //Prints month. Adds a 0 if the month is below ten
  if (getMonth() < 10)
    cout << "Date: 0" << getMonth();
  else cout << "Date: " << getMonth();

  //Prints day. Adds a 0 if the day is below ten
  if (getDay() < 10)
    cout << "-0" << getDay();
  else cout << "-" << getDay();

  //Prints year
  cout << "-" << getYear() << endl;
}

//Precond: The date is initialized
//Ponstcond: The number of days passed, including the current day, is returned
int dateType::numDaysPassed()
{
  int sum = getDay();
  for (int i = 0; i != getMonth() - 1; i++)
    {
      sum += days[i];
    }
  if (isLeapYear(getYear()) && getMonth() >= 3)
    sum++;
  return sum;
}

//Precond: The date is initialized
//Postcond: The number of days remaining after the current date is returned
int dateType::numDaysRemaining()
{
  return numDaysInYear() - numDaysPassed();
}

//Precond: The date is initialized and a new integer is inputted
//Postcond: The date advances by the number of days determined by the integer
void dateType::futureDate(int num)
{
  if (day + num > numDaysInMonth())
  {
    if (getMonth() == 12)
      setDate(1, (day + num) - numDaysInMonth(), getYear() + 1);
    else setDate(getMonth() + 1, (day + num) - numDaysInMonth(), getYear());
  }
  else setDate(getMonth(), (day + num), getYear());
}