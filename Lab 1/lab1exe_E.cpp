/*
 *  lab1exe_E.cpp
 *  ENSF 619 Lab 1 Exercise E1
 *  Created by Mahmood Moussavi
 *  Completed by: Jeremy Sugimoto
 *  Submission Date: Sept 20,2023
 *
 */

#include <iostream>
using namespace std;

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr);

int main(void)
{
  int millisec;
  int minutes;
  double seconds;
    
  cout << "Enter a time interval as an integer number of milliseconds: ";
  
  cin >> millisec;
  
  if (!cin) {
    cout << "Unable to convert your input to an int.\n";
    exit(1);
  }
  
  cout << "Doing conversion for input of " <<  millisec <<" milliseconds ... \n";
  
  time_convert(millisec,&minutes,&seconds);
  
  cout << "That is equivalent to " << minutes << " minute(s) and " << seconds << " second(s).\n";
  
  return 0;
}

void time_convert(int ms_time, int *minutes_ptr, double *seconds_ptr)
{
*minutes_ptr = ms_time / (1000*60); 
*seconds_ptr = (ms_time % (1000*60))/1000.0;
}