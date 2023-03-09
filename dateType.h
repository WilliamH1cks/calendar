#include <iostream>
using namespace std;

//Class definition of dayType
class dateType
{
  //Public functions:
  public:
  void setYear(int i); //Sets the current year
  int getYear(); //Gets current year

  void setMonth(int i); //Sets the current month
  int getMonth(); //Gets current month

  void setDay(int i); //Sets the current day
  int getDay(); //Gets current day

  void setDate(int m, int d, int yr);

  bool isLeapYear(int yr); //Checks if the year is a leap year
  int numDaysInMonth(); //Counts the number of days in the month
  int numDaysInYear(); //Counts the number of days in the year
  void printNumDays(); //Prints the results of the two above functions
  void printDate(); //Prints current date
  int numDaysPassed(); //Informs the user how many days have passed
  int numDaysRemaining(); //Informs the user how many days remain
  void futureDate(int numDays); //Sets the date to a future date
  
  //Constructors:
  dateType(); //Deafult constructor, defaults to 1/1/1900
  dateType(int m, int d, int yr); //Uses given vals as the date, taking values in MM/DD/YYYY format

  private:
  int year; //Integer representing year. Will be forced above 1900.
  int month; //Integer spanning 1 - 12 representing the month
  int day; //Integer spanning 1 - 31, limits based on the month and year
};
