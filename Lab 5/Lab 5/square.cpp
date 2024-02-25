#include "square.h"
#include <iostream>
using namespace std;

// Constructor for the Square class, initializing its members
Square::Square(double x, double y, double side_a, const char* name) : Shape(x, y, name), side_a(side_a) {
    // The constructor initializes the base class's members using the base class constructor
}

// Calculate and return the area of the square
double Square::area() const {
    return side_a * side_a;
}

// Calculate and return the perimeter of the square
double Square::perimeter() const {
    return 4 * side_a;
}

// Getter method to retrieve the value of the side length (side_a)
double Square::getSideA() const {
    return side_a;
}

// Setter method to set the value of the side length (side_a)
void Square::setSideA(double side_a) {
    this->side_a = side_a;
}

// Display information about the square, including its base class information
void Square::display() const {
    Shape::display();  // Call the display method of the base class (Shape)
    cout << "Side a: " << side_a << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
