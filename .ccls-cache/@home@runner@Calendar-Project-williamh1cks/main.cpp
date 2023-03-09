#include <iostream>
#include "dayType.h"
#include "dateType.h"
using namespace std;

//Main function
int main()
{
  cout << "From dayType section (Part I):" << endl;
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

  cout << endl << endl << "From dateType section (Part II):" << endl;
  dateType testDate;
  cout << "Default constructor: ";
  testDate.printDate();
  dateType date1(2, 20, 2003);
  cout << "Parameter constructor: ";
  date1.printDate();
  cout << "Number of days passed: " << date1.numDaysPassed() << endl;
  cout << "Number of days left: " << date1.numDaysRemaining() << endl;
  date1.printNumDays();
  date1.futureDate(15);
  cout << "Date after 15 days: ";
  date1.printDate();
  cout << "Resetting year to 2000: ";
  date1.setYear(2000);
  cout << date1.getYear() << endl;
  date1.printDate();
  cout << "Resetting month to 2: ";
  date1.setMonth(2);
  cout << date1.getMonth() << endl;
  date1.printDate();
  cout << "Resetting day to 29: ";
  date1.setDay(29);
  cout << date1.getDay() << endl;
  date1.printDate();
  cout << "Resetting year to 2001: ";
  date1.setYear(2001);
  cout << date1.getYear() << endl;
  date1.printDate();
  cout << "Resetting month to 0: ";
  date1.setMonth(0);
  cout << date1.getMonth() << endl;
  cout << "Final date: ";
  date1.printDate();

  return 0;
};