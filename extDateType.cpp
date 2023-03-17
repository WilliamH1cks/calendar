#include <iostream>
#include "extDateType.h"
using namespace std;

//Static array, stores name of months
string const months[13] = {"Unused", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

//Constructors
extDateType::extDateType()
{
  setDate(1, 1, 1900);
};

extDateType::extDateType(int m, int d, int yr)
{
  setDate(m, d, yr);
};

//Functions

//Precond: The date and month name is initialized
//Postcond: (Month) (Date), (Year) is printed
void extDateType::printLongDate()
{
  cout << "Date in word format: " << monthName << " " << getDay() << ", " << getYear() << endl;
}

//Precond: The month name is initialized
//Postcond: The month name is returned
string extDateType::getMonthName()
{
  return monthName;
}

//Precond: The date and month name is initialized
//Postcond: (Month) (Year) is printed
void extDateType::printLongMonthYear()
{
  cout << monthName << " " << getYear() << endl;
}

//Precond: The date and month name is initialized
//Postcond: The month name is printed
void extDateType::printLongMonth()
{
  cout << "Date in word format: " << monthName << endl;
}

//Precond: a new integer representing a month, following the dateType constraints for the integer's range
//Postcond: The month name and number is set/reset
void extDateType::setMonth(int m)
{
  dateType::setMonth(m);
  monthName = months[getMonth()];
}

//Precond: Three integers
//Postcond: The date and month name is set/reset
void extDateType::setDate(int m, int d, int yr)
{
  setMonth(m);
  setDay(d);
  setYear(yr);
}

//Precond: Date initialized, integer to advance to
//Postcond: New date, as given from the dateType class, and the new month (in case the month changes)
void extDateType::futureDate(int i)
{
  dateType::futureDate(i);
  setMonth(getMonth());
}