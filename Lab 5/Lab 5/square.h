#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"  // Include the definition of the base class "Shape"

class Square : public Shape {  // Define the Square class that inherits from Shape
private:
    double side_a;  // Private member variable to store the side length of the square

public:
    // Constructor for the Square class
    Square(double x, double y, double side_a, const char* name);

    // Override the base class's virtual function to calculate the area
    double area() const override;

    // Override the base class's virtual function to calculate the perimeter
    double perimeter() const override;

    // Getter method to retrieve the value of side_a
    double getSideA() const;

    // Setter method to set the value of side_a
    void setSideA(double side_a);

    // Override the base class's virtual function to display square information
    void display() const override;
};

#endif
