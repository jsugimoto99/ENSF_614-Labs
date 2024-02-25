#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : virtual public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double x, double y, double radius, const char* name);

    // Override Area calculation function
    double area() const override;

    // Overrdie Perimeter calculation function (Circumference)
    double perimeter() const override;

    // Getter and Setter for radius
    double getRadius() const;
    void setRadius(double newRadius);

    // Override Display function
    void display() const override;
};

#endif
