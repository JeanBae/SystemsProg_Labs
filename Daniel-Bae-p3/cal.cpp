/* 
 Author: Stone Daniel and Bae Jean
Purpose: Implementation of cal unix function
Date: Tuesday April 11, 2017
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <unistd.h>
#include <fcntl.h>
#include <string>
#include <iomanip>
#include <time.h>
using namespace std;





void printCal(int month, int year)
{
  string m[] = {"January", "February","March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  //  string d[] = {"Su", "Mo","Tu", "We", "Th", "Fr", "Sa"};
  
  int day = 1;
  int y = year -(14-month)/12;
  int m1 = month +12 * ((14-month)/12)-2;
  int firstDay = (day + y + y/4 - y/100 + y/400 + (31*m1/12))%7;
  int daysinMonth;
  if(year<1752)
    {
      firstDay -=2 ;
      int leaps;
      leaps = year/100;
      leaps -= leaps/4;
      if(firstDay == -1)
	firstDay = 6;
      if(firstDay == -2)
	firstDay = 5;
      firstDay+= leaps;
      firstDay = firstDay % 7;
    }
  if(month == 9 && year == 1752)
    {//argc would be two, run command and month with no arg after
      //year = month;
      //cout << " YOU MADE IT IN" << endl;
      cout << setw(21) <<  m[month-1] << " " << year;
      cout <<"\nSu\tMo\tTu\tWe\tTh\tFr\tSa" << endl;
     
      int count = 0;
      for(count = 0;count<2;count++)
	cout << "\t";
      cout << 1 << "\t";
      cout << 2 << "\t";
      //cout << setw(2) << 1 << "\t";
      //cout << setw(2) << 2 << "\t";
      for(int startDate = 14;startDate <= 30;startDate++)
	{
	  cout << startDate << "\t";
	  if(startDate == 16 || startDate == 23 || startDate == 30)
	    cout << endl;
	}
      cout << endl << endl;
    }
  
  
  
  else{
    switch(month)
      {
      case 1:
	cout << setw(21) << m[month-1] << year;
	daysinMonth = 31;
	break;
      case 2:
	cout << setw(21) << m[month-1] << year;
	if(((year%400 == 0) || (year % 4 == 0 && year % 100 != 0)) && (year >= 1752))//&&
	  daysinMonth = 29;
	else if(((year%400 == 0) || (year % 4 == 0 && year % 100 != 0)) && (year >= 1752))
	  daysinMonth = 28;
	else if(year%4 == 0 && year < 1753)
	  daysinMonth = 29;
	else
	  daysinMonth = 28;
	break;
      case 3:
	cout << setw(21) << m[month-1] << year;
	daysinMonth = 31;
	break;
      case 4:
	cout << setw(21) << m[month-1] << year;
	daysinMonth = 30;
	break;
      case 5:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 31;
	break;
      case 6:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 30;
	break;
      case 7:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 31;
	break;
      case 8:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 31;
	break;
      case 9:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 30;
	break;
      case 10:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 31;
	break;
      case 11:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 30;
	break;
      case 12:
	cout << setw(21) <<  m[month-1] << year;
	daysinMonth = 31;
	break;
      }
    cout <<"\nSu\tMo\tTu\tWe\tTh\tFr\tSa" << endl;
    //cout << setw(2);	
    
    int count = 0;
    for(count = 0;count<firstDay;count++)
      cout << "\t";
    //cout << firstDay << endl;
    for(int startDate = 1;startDate <= daysinMonth;startDate++)
      {
	cout << startDate << "\t";
	if((startDate + firstDay)% 7 == 0)
	  cout << endl;
      }
    cout << endl << endl;
  }
  
}


int main(const int argc, const char * argv []){

  int month = 0;;
  int year = 0;
  
  time_t theTime = time(NULL);
  struct tm *aTime = localtime(&theTime);
  

  if(argc == 1)
    {
      month = aTime->tm_mon + 1; 
      year = aTime->tm_year + 1900;
      printCal(month, year);
    }
  else if(argc == 2)
    {
      year = atoi(argv[1]);//check is digit
      for(int j = 1;j<=12;j++)
	{
	  printCal(j,year);
	}
    }
  else
    {
      month = atoi(argv[1]);
      year = atoi(argv[2]);
      printCal(month,year);
    }
  
  
}//end of main


