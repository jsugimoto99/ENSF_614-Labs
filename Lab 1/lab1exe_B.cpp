/*
 *  lab1exe_B.cpp
 *  ENSF 614 Lab 1, exercise B
 *  Created by Mahmood Moussavi
 *  Completed by: Jeremy Sugimoto
 *  Submission Date: Sept 20, 2023
 */

#include <iostream>
#include <cmath>
#include <math.h>
#include<iomanip>
using namespace std;

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void){
    double velocity;
    
    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;
    
    if(!cin){  // means if cin failed to read
        cout << "Invlid input. Bye...\n";
        exit(1);
    }
    while (velocity < 0 ){
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if(!cin){
            cout << "Invlid input. Bye...";
            exit(1);
        }
    }
    create_table(velocity);

    return 0;
}

double degree_to_radian(double d){
   double r = d * PI/180; // Converting degrees to radians
   return r;
}
double Projectile_travel_time(double a, double v){
    double t = (2*v*sin(degree_to_radian(a)))/G; // Time equation given in assignment.
    return t;
}
double Projectile_travel_distance(double a, double v){
    double d = (v*v / G)*sin(2*degree_to_radian(a)); // Distance equation given in assignment.
    return d;
}
void create_table(double v){
    double a = 0;
    int colWidth = 15;
    //Table Header
    cout << setfill('-') << setw(3*colWidth) << "-" << endl;
    cout << setfill(' ') << fixed;
    cout << setw(colWidth) << "Angle" << setw(colWidth) << "  t  " << setw(colWidth) << " d " << endl;
    cout << setw(colWidth) << "(deg)" << setw(colWidth) << "(sec)" << setw(colWidth) << "(m)" << endl;
    cout << setfill('-') << setw(3*colWidth) << "-" << endl;
    cout << setfill(' ') << fixed;
    // Populate table
    while (a <= 90){ // angle from 0 to 90.
        cout << setw(colWidth) << a << setw(colWidth) << Projectile_travel_time(a,v) << setw(colWidth) << Projectile_travel_distance(a,v) << endl;
        a += 5; // Increment angles by 5 degrees.
    }
}
