/*
 *
 * lab2exe_A.cpp
 * ENSF 614 Lab 2 - Execise A
 * Completed by: Jeremy Sugimoto
 * Submission Date: Sept 27, 2023
 */
/********************************************************************
 One objective of this program is to use sizeof operator to find the number of
 bytes of memory alloacted for simple varibles, pointers, and arrays.
 
 The second objective is is to demonstrate how array notations in a function
 argument is still treated as a pointer.
 
 ********************************************************************/
#include <iostream>
using namespace std;

void try_to_change(double* dest);
void try_to_copy(double dest[], double source[]);
double add_them (double a[5]);

int main(void)
{
    double sum = 0;
    double x[4];
    double y[] = {2.3, 1.2, 2.0, 4.0};
    cout << " sizeof(double) is " << (int) sizeof(double) << " bytes.\n";
    cout << " size of x in main is: " << (int) sizeof(x) << " bytes.\n";
    cout << " y has " << (int) (sizeof(y)/ sizeof(double)) << " elements and its size is: " <<  (int) sizeof(y) << " bytes.\n";
    
    /* Point one */
    
    try_to_copy(x, y);
    
    try_to_change(x);
    
    sum = add_them(&y[1]);
    cout << "\n sum of values in y[1], y[2] and y[3] is: " << sum << endl;
    
    for (size_t i = 0; i < 4; i++) {
        std::cout << y[i] << ' ';
    }

    cout << "\n" << endl;
    for (size_t i = 0; i < 4; i++) {
        std::cout << x[i] << ' ';
    }
    return 0;
}


void try_to_copy(double dest[], double source[])
{
    dest = source;
    
    /* point two*/
    
    return;
}

void try_to_change(double* dest)
{
    dest [3] = 49.0;
    
    /* point three*/
    cout << "\n sizeof(dest) in try_to_change is "<< (int)sizeof(dest) << " bytes.\n";
    return;
}


double add_them (double arg[5])
{
    *arg = -8.25;
    
    /* point four */
    cout << "\n sizeof(arg) in add_them is " << (int) sizeof(arg) << " bytes.\n";
    cout << "\n Incorrect array size computation: add_them says arg has " << (int) (sizeof(arg)/sizeof(double)) <<" element.\n";
    
    return arg[0] + arg[1] + arg[2];
}
