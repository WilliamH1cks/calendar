#include <iostream>
#include "dayType.h"
using namespace std;

//Main function
int main()
{
  //Calls new dayType
  dayType day1;
  //Prints current day (Sunday)
  cout << "From default constructor: ";
  day1.printDay();
  //Prints next day
  cout << "Next day: " << day1.getNextDay() << endl;
  //Prints previous day
  cout << "Previous day: " << day1.getPrevDay() << endl;

  //Calls new dayType
  dayType day2(1);
  //Prints current day (Monday)
  cout << "From constructor wih parameters: ";
  day2.printDay();
  //Adds 3 days, prints
  day2.addDays(3);
  cout << "After 3 days: ";
  day2.printDay();
  //Adds 30 days, prints
  day2.addDays(30);
  cout << "After 30 days: ";
  day2.printDay();
  //Adds 365 days, prints
  day2.addDays(365);
  cout << "After 365 days: ";
  day2.printDay();

  return 0;
};