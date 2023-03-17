#include <iostream>
using namespace std;

//Class definition of dayType
class dayType
{
  //Public functions:
  public:
  void setDay(int i); //Sets the current day (day, dayNum) usng dayName[]
  void printDay(); //Prints the current day
  void addDays(int i); //Adds i to dayNum and finds associated day using dayName[]
  string getDay(); //Fetches cuurent day
  int getDayNum(); //Fecthes dayNum
  string getNextDay(); //Fetches next day (day of dayNum + 1)
  string getPrevDay(); //Fetches previous day (day of (dayNum + 7) - 1)
  
  //Constructors:
  dayType(); //Deafult constructor, defaults to day = Sunday, dayNum = 0
  dayType(int val); //Uses given val as dayNum, fetches associated day from dayName[]

  private:
  int dayNum; //Index integer used to set or change any object with the associated day of the week. Index 0 is Sunday
  string day; //String storing the day of the week itself the current object is set as
};
