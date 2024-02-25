#ifndef CURVECUT_H
#define CURVECUT_H

#include "rectangle.h"
#include "circle.h"

class CurveCut : public Rectangle, public Circle, public Shape{
public:
    // Constructor
    CurveCut(double x, double y, double width, double length, double radius, const char* name);

    // Override area function
    double area() const override;

    // Override perimeter function
    double perimeter() const override;

    // Override display function
    void display() const override;
};

#endif
