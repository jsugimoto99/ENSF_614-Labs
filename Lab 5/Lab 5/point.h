// point.h
// ENSF 614 Fall 2023 Lab 5 - Exercise A

#ifndef POINT_H
#define POINT_H

class Point{
private:
    double x;
    double y;
    int id; // ID number

public:
    Point(double x, double y); // Constructor
    void display() const; // Display func
    double getX() const; // Getter for X
    double getY() const; // Getter for y
    int getId() const; // Getter for id
    void setX(double xSet); // Setter for X
    void setY(double ySet); // Setter for Y
    static int counter(); // Function to return the number of objects
    double distance(const Point& other) const; // Non-static distance function
    static double distance(const Point& p1, const Point& p2); // Static distance function


};
#endif