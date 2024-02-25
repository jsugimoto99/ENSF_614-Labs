#include "circle.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor
Circle::Circle(double x, double y, double radius, const char* name) : virtual Shape(x, y, name), radius(radius) {}

// Area calculation function
double Circle::area() const {
    return M_PI * radius * radius;
}

// Perimeter calculation function (Circumference)
double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

// Getter for radius
double Circle::getRadius() const {
    return radius;
}

// Setter for radius
void Circle::setRadius(double newRadius) {
    radius = newRadius;
}

// Display function
void Circle::display() const {
    Shape::display();
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
