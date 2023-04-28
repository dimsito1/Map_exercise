#pragma once 
#include <iostream>
#include <cstring>
#include <cmath>

class Location{
private:
    char* name;
    double x, y;

public:
    Location();
    Location(const char* newName, const double newX, const double newY);
    Location(const Location& other);
    Location& operator=(const Location& other);
    ~Location();
    
    const char* getName() const;
    const double getX() const;
    const double getY() const;

    void printLocation() const;
};
