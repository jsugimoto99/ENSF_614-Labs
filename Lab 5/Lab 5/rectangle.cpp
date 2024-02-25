#include "rectangle.h"
#include <iostream>
using namespace std;

// Constructor for the Rectangle class, initializing its members
Rectangle::Rectangle(double x, double y, double side_a, double side_b, const char* name)
    : virtual Shape(x, y, name), side_a(side_a), side_b(side_b) {
    // The constructor initializes the base class's members using the base class constructor
}
Rectangle::Rectangle(const Rectangle& other) : Shape(other), side_a(other.side_a), side_b(other.side_b) {
    // Copy the properties of the other Rectangle
}

// Calculate and return the area of the rectangle
double Rectangle::area() const {
    return side_a * side_b;
}

// Calculate and return the perimeter of the rectangle
double Rectangle::perimeter() const {
    return 2 * (side_a + side_b);
}

// Getter method to retrieve the value of side_a (width)
double Rectangle::getSideA() const {
    return side_a;
}

// Setter method to set the value of side_a (width)
void Rectangle::setSideA(double side_a) {
    this->side_a = side_a;
}

// Getter method to retrieve the value of side_b (height)
double Rectangle::getSideB() const {
    return side_b;
}

// Setter method to set the value of side_b (height)
void Rectangle::setSideB(double side_b) {
    this->side_b = side_b;
}

// Display information about the rectangle, including its base class information
void Rectangle::display() const {
    Shape::display();  // Call the display method of the base class (Shape)
    cout << "Side a (width): " << side_a << endl;
    cout << "Side b (height): " << side_b << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
    cout << endl;  // Add an extra line for spacing
}
