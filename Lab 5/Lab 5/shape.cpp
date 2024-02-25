#include "shape.h"
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

Shape::Shape(double x, double y, const char* name) : origin(Point(x, y)) {
    
    shapeName = new char[strlen(name) + 1];
    strcpy(shapeName, name);
}

double Shape::area() const{
    return 0.0;
}

double Shape::perimeter() const{
    return 0.0;
}
Shape::~Shape() {
    if(shapeName!= NULL){
        delete[] shapeName;
    }
       
  
}

const Point& Shape::getOrigin() const {
    return origin;
}

const char* Shape::getName() const {
    return shapeName;
}

void Shape::display() const {
    cout << "Shape Name: " << shapeName << endl;
    cout << "X-coordinate: " << origin.getX() << endl;
    cout << "Y-coordinate: " << origin.getY() << endl;
}

double Shape::distance(Shape& other) const {
    return origin.distance(other.getOrigin());
}

double Shape::distance(const Shape& the_shape, const Shape& other) {
    return the_shape.origin.distance(other.origin);
}

void Shape::move(double dx, double dy) {
    origin.setX(dx);
    origin.setY(dy);
}
