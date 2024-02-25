#include "point.h"  // Include the user-defined header file for the Point class
#include <iostream>  // Include the standard input/output stream library
#include <cmath>     // Include the math library for mathematical functions
using namespace std;  // Using the standard namespace

int count = 1000;  // Initialize a global count variable with the value 1000

// Constructor for the Point class, initializes x, y, and assigns a unique id
Point::Point(double x, double y): x(x), y(y){
    count++;  // Increment the global count variable
    id = count;  // Assign the unique id based on the global count
}

// Member function to display the coordinates of the point
void Point::display() const {
    cout << "X-coordinate: " << x << endl;
    cout << "Y-coordinate: " << y << endl;
}

// Getter method for retrieving the X-coordinate
double Point::getX() const {
    return x;
}

// Getter method for retrieving the Y-coordinate
double Point::getY() const {
    return y;
}

// Setter method to set the X-coordinate
void Point::setX(double xSet) {
    x = xSet;
}

// Setter method to set the Y-coordinate
void Point::setY(double ySet) {
    y = ySet;
}

// Getter method to retrieve the unique id of the point
int Point::getId() const {
    return id;
}

// Static member function to calculate the number of Point objects created
int Point::counter() {
    return count - 1000;
}

// Member function to calculate the Euclidean distance between two points
double Point::distance(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

// Static member function to calculate the Euclidean distance between two points
double Point::distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}
