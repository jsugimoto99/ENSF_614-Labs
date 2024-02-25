/*
* lab2exe_C.cpp
* ENSF 614 Lab 2 Exercise C
* Completed by: Jeremy Sugimoto
* Submission Date: Sept 27, 2023
*/ 


#include <iostream>
using namespace std;

int what(const int *a, int n);

// This function was not written for easy readability!
// It's a drill exercise about pointer arithmetic!
int what(const int *a, int n)
{
  const int *max = a, *min = a + n - 1, *guard = a + n;
  cout << endl << "*max " << *max << endl << "*min " << *min << endl <<"*guard " << *guard << endl;
  cout << "max " << max << endl << "min " << min << endl << "guard " << guard << endl << endl;
  const int *p, *q;

  cout << "*a: " <<  *a << endl;
  cout << "a: " << a << endl;
  for (p = a + 1; p != guard; p++) {
    cout << "p: " << p << endl << "*max: " << *max << endl;
    if (*p > *max)
      max = p;
      cout << "max: " << max << endl << endl;
  }
  cout << "q loop:" << endl << endl;
  for (q = a + n - 1; q != a; q--) {
    cout << "q: " << q << endl << "*min: " << *min << endl;
    if (q[-1] < *min)
      min = q - 1;
      cout << "min: "<< min;
  }
 cout << "*max " << *max << endl << "*min " << *min << endl <<"*guard " << *guard << endl;
  cout << "max " << max << endl << "min " << min << endl << "guard " << guard << endl << endl << endl;
  cout << "end of what.." << endl <<endl;
   // point one (after the 2nd loop has finished)

  return min - max;
}

int main(void)
{
  int w;
  
  int x[] = {99, 0, 0, -99, 0, 0};
  int y[] = {1, 0, 100, 2, 0, 3};
  int *P = x;
  
  cout << "x array: " << endl;
  for(int i = 0; i<sizeof(x); i++){
    cout << &x[i] << endl;
  }

  cout <<endl<<endl<< "y array: " << endl;
  for(int j = 0; j<sizeof(y); j++){
    cout << &y[j] << endl;
  }
  
  cout << "*x: " <<*x << endl << "*y: " << *y << endl << "P: " << P << endl;
   cout << "x: " <<x << endl << "y: " << y << endl << "*P: " << *P << endl;
  

  cout << "size of x: " << sizeof(x) << endl;
  cout << "size of y: " << sizeof(y) << endl;
  cout << "size of int: " << sizeof(int)<<endl;
  w = what(x, sizeof(x) / sizeof(int));
  cout << "1st result: " << w << ".\n";
  w = what(y, sizeof(y) / sizeof(int));
  cout << "2nd result: " << w << ".\n";
  return 0;
}
