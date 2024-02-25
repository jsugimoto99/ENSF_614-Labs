#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : virtual public Shape{
private: 
    double side_a;
    double side_b;

public:
    Rectangle(double x, double y, double side_a, double side_b, const char* name); // Constructor
    Rectangle(const Rectangle& other); // Copy Constrcuter
    double area() const override; // Calculate and return the area of a rectangle
    double perimeter() const override; // Calculate and return the perimeter of a rectangle
    double getSideA() const; // Getter for side_a
    void setSideA(double side_a); // Setter for side_a
    double getSideB() const; // Getter for side_b
    void setSideB(double side_b); // Setter for side_b
    void display() const override; // Display the properties of the rectangle
};

#endif
