#ifndef calendarType_H
#define calendarType_H

#include <iostream>
#include "extDateType.h"
#include "dayType.h"
using namespace std;

//Class definition of calendarType
class calendarType
{
  //Public members
  public:
  void setMonth(int m); //Sets month and updates month name
  string getMonth(); //Fetches month name
  int getMonthIndex(); //Fetches month number
  void setYear(int yr); //Sets year
  int getYear(); //Fetches year
  int getMonthLength(); //Fetches number of days in month
  void printCalendar(string month, int mNum, int yr, int monthLength); //Prints entire calendar

  //Constructors
  calendarType(int m, int yr); //Constructor with month and year

  //Private members
  private:
  int firstDayOfMonth(int m, int yr); //Sets firstDay variable
  void printCalHeading(string m, int yr); //Prints month year, and column headings of days of the week
  void printDayNums(int dNum, int daysInMonth); //Prints the day numbers of the month, starting at an offset dtermined by the dayType of the first day
  dayType firstDay; //Notes the day of the week the first date of the month is
  extDateType firstDate; //Stores the first date
  
};

#endif

