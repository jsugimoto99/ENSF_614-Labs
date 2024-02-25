#include "curveCut.h"
#include <iostream>
#include <cmath>
using namespace std;

// Constructor
CurveCut::CurveCut(double x, double y, double width, double length, double radius, const char* name)
    : Rectangle(x, y, width, length, name), Circle(x, y, radius, name), Shape(x, y, name) {
    if (radius > width / 2.0 || radius > length / 2.0) {
        cerr << "\nError: Radius is too large for the given dimensions." << endl;
        exit(1);
    }
}

// Override area function
double CurveCut::area() const {
    double rectArea = Rectangle::area();
    double circleArea = Circle::area();
    return rectArea - circleArea;
}

// Override perimeter function
double CurveCut::perimeter() const {
    double rectPerimeter = Rectangle::perimeter();
    double circlePerimeter = Circle::perimeter();
    return rectPerimeter + circlePerimeter;
}

// Override display function
void CurveCut::display() const {
    cout << "CurveCut Name: " << Rectangle::getName() << endl;
    cout << "X-coordinate: " << Rectangle::getOrigin().getX() << endl;
    cout << "Y-coordinate: " << Rectangle::getOrigin().getY() << endl;
    cout << "Width: " << Rectangle::getSideA() << endl;
    cout << "Length: " << Rectangle::getSideB() << endl;
    cout << "Radius of the cut: " << Circle::getRadius() << endl;
}
