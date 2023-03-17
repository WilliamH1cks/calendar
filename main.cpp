#include <iostream>
#include "calendarType.h"
using namespace std;

//Main function
int main()
{
  int mes;
  int ano;
  cout << "Please enter your month number index (Between 1 and 12): ";
  cin >> mes;
  cout << "Please enter your year (Earliest year supported is 1900): ";
  cin >> ano;
  calendarType cal(mes, ano);
  cal.printCalendar(cal.getMonth(), cal.getMonthIndex(), cal.getYear(), cal.getMonthLength());
};