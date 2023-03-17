#include <iostream>
#include <cassert>
#include <cstring>
#include "calendarType.h"
using namespace std;

//Constructors

calendarType::calendarType(int m, int yr) : firstDate(m, 1, yr)
{
  //cout << "Test";
  assert(yr >= 1900);
  assert(m >= 1 && m <= 12);
  firstDay.setDay(firstDayOfMonth(m, yr));
  //cout << firstDay.getDay();
};

//Functons

//Precond: An integer
//Postcond: The month to use is set
void calendarType::setMonth(int m)
{
  firstDate.setMonth(m);
}

//Precond: The month is initialized
//Postcond: Returns the month's name
string calendarType::getMonth()
{
  return firstDate.getMonthName();
}

//Precond: The month is initialized
//Postcond: The month's index is returned (1 for Jan, 2 for Feb, 3 for Mar, etc.)
int calendarType::getMonthIndex()
{
  return firstDate.getMonth();
}

//Precond: An integer
//Postcond: The year is set
void calendarType::setYear(int yr)
{
  firstDate.setYear(yr);
}

//Precond: The year is initialized
//Postcond: Returns the year
int calendarType::getYear()
{
  return firstDate.getYear();
}

//Precond: The month and year to print is determined
//Postcond: Prints the Month and Year followed by abbreviated versions of the weekdays (as column headings)
void calendarType::printCalHeading(string m, int yr)
{
  cout << endl << endl;
  firstDate.printLongMonthYear();
  cout << "Sun   Mon   Tue   Wed   Thu   Fri   Sat" << endl;
}

//Precond: The month and year to print is determined, and the weekday of the first day is found
//Postcond: The days are printed within their respective columns, based on their weekdays
void calendarType::printDayNums(int dNum, int daysInMonth)
{
  int dayIndex = 0;
  //cout << daysInMonth;
  for (int i = 0; i != dNum; i++)
    cout << "      ";
  for (int i = 1; i <= daysInMonth; i++)
  {
    if (i < 10)
      cout << "  " << i << "   ";
    else cout << " " << i << "   ";
    dNum += 1;
    if (i == daysInMonth)
    {
      cout << endl << endl;
      return;
    }
    if (dNum % 7 == 0)
    {
      cout << endl;
      dNum = 0;
    }
  }
}

//Precond: The month and year is determined
//Postcond: Determines the weekday of the first date of the month
int calendarType::firstDayOfMonth(int m, int yr)
{
  dayType dayOne;
  int sumDays = 0;
  for (int i = 1900; i < yr; i++)
  {
    extDateType tempDay(1, 1, i);
    sumDays += tempDay.numDaysInYear();
  }
  for (int i = 1; i < m; i++)
  {
      extDateType tempDay(i, 1, yr);
      sumDays += tempDay.numDaysInMonth();
  }

  //cout << sumDays;
  //sumDays %= 7;
  //cout << sumDays;
  
  dayOne.setDay(sumDays + 1);
  return dayOne.getDayNum();
}

//Precond: The month's name and length, the year, and the weekday of the first day are determined
//Postcond: Prints the entire calendar, using two defined functions (above)
void calendarType::printCalendar(string month, int mNum, int yr, int monthLength)
{
  printCalHeading(month, yr);
  //cout << firstDay.getDayNum();
  printDayNums(firstDay.getDayNum(), monthLength);
}

//Precond: The month and year are determined
//Postcond: The length of the month in question is fetched
int calendarType::getMonthLength()
{
  return firstDate.numDaysInMonth();
}