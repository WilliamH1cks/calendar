#include <iostream>
#include "dateType.h"
using namespace std;

//Class definition
class extDateType : public dateType
{
  //Public members
  public:
  void printLongDate(); //Prints date in Month Date, Year format
  void printLongMonthYear(); //Prints date in Month Year format
  void printLongMonth(); //Prints the month name
  void setMonth(int m); //Sets month name
  void setDate(int m, int d, int yr); //Sets date, now includes month name
  void futureDate(int numDays); //Advances date, needed to change month
  string getMonthName(); //Fetches monthName, used in calendarType

  //Constructors
  extDateType();
  extDateType(int m, int d, int yr);

  //Private members
  private:
  string monthName;
};