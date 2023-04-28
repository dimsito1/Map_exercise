#include "location.hpp"

Location::Location() : name(nullptr), x(0), y(0) {};

Location::Location(const char* newName, const double newX, const double newY) {
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
    x = newX;
    y = newY;
}

Location::Location(const Location& other) {
    if (this != &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        x = other.x;
        y = other.y;
    }
    else { name = nullptr; }
}

Location& Location::operator=(const Location& other) {
    if (this != &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        x = other.x;
        y = other.y;
    }
    return *this;
}

Location::~Location() {
    delete[] name;
}

const char* Location::getName() const {
    return name;
}
const double Location::getX() const {
    return x;
}
const double Location::getY() const {
    return y;
}

void Location::printLocation() const {
    if (name) {
        std::cout << "Name: " << name << std::endl;
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
    } 
    else {
            std::cout << "Name not set." << std::endl;
    }
}

