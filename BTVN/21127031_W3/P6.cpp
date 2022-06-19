#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include <conio.h>

using namespace std;

int main()
{
  char key;
  int sec_prev=0;
  while(1)
  {
    int seconds, minutes, hours;
    string str;
  
    //storing total seconds
    time_t total_seconds=time(0);
  
    //getting values of seconds, minutes and hours
    struct tm* ct=localtime(&total_seconds);
  
    seconds=ct->tm_sec;
    minutes=ct->tm_min;
    hours=ct->tm_hour;
    
    //converting it into 12 hour format
    if(hours>=12)
      str="PM";
    else
      str="AM";
    hours=hours>12?hours-12:hours;	
    
    
    //printing the result
    if(seconds==sec_prev+1 || (sec_prev==59 && seconds==0))
    {
      system("CLS");
      cout<< (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str <<endl;
      if (sec_prev==59 && seconds==0)
      {
          Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
      }
      
      if (kbhit())
      {
        key = getch();
        if (key==27) break;
      }
    }
    
    sec_prev=seconds;
    
  }
  
  return 0;
}