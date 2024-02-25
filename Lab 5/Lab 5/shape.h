#ifndef SHAPE_H
#define SHAPE_H

#include "point.h" // Inherits Point class

virtual class Shape {
private:
    Point origin;
    char* shapeName;

public:
    Shape(double x, double y, const char* name); // Constructor
    ~Shape(); // Destructor
    const Point& getOrigin() const; // Getter for origin
    const char* getName() const; // Getter for name
    virtual void display() const; // Display function
    double distance(Shape& other) const; // Non-static distance function
    static double distance(const Shape& the_shape, const Shape& other); // Static distance function
    void move(double dx, double dy); // Move function
    virtual double area() const; // Shape area
    virtual double perimeter() const; // Shape Perimeter
};

#endif
