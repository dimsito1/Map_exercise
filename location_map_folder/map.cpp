#include "map.hpp"

void Map::resize(int newCapacity) {
    Location* newArray = new Location[newCapacity];
    for (size_t i = 0; i < size; i++){
        newArray[i] = array[i];
    }
    Location* oldArray = array;
    array = newArray;
    capacity = newCapacity;
    delete[] oldArray;
}

Map::Map() : size(0), capacity(1) {
    array = new Location[capacity];
}

Map::Map(const int initCapacity) {
    array = new Location[initCapacity];
    size = 0;
    capacity = initCapacity;
} 

Map::Map(const Map& other) {
    copyFrom(other);
}

Map& Map::operator=(const Map& other) {
    if (this != &other) {
        delete[] array;
        copyFrom(other);
    }
    return *this;
}

Map::~Map() {
    delete[] array;
}

void Map::copyFrom(const Map& other) {
    array = new Location[other.capacity];
    for (size_t i = 0; i < other.size; i++){
        array[i] = other.array[i];
    }
    size = other.size;
    capacity = other.capacity;
}

void Map::addToMap(const Location& other) {
    if (size == capacity) {
        int newCapacity = capacity * 2;
        resize(newCapacity);
    }
    array[size++] = other;
}

void Map::printMap() const {
    std::cout << "Map: " << std::endl;
    for (size_t i = 0; i < size; i++){
        std::cout << "-Location" << i + 1 << ' ' << array[i].getName()
            << ", (" << array[i].getX() << "," << array[i].getY() << ')' << std::endl; 
    }
}

void Map::distance(const int first, const int second) {
    double dx = array[first].getX() - array[second].getX();
    double dy = array[first].getY() - array[second].getY();
    double dist = std::sqrt(dx * dx + dy * dy);
    std::cout << "The distance is: " << dist << std::endl;
}

void Map::getShortestDistance(const int index) {
    double* distanceArray = new double[size];
    for (size_t i = 0; i < size; i++) {
        double dx = array[i].getX() - array[index].getX();
        double dy = array[i].getY() - array[index].getY();
        distanceArray[i] = std::sqrt(dx * dx + dy * dy);
    }

    int newIndex;
    double minDistance;
    for (size_t i = 0; i < size; i++)
    {
        if (distanceArray[i] != 0) {
            minDistance = distanceArray[i];
            newIndex = i;
            break;
        }
    }
    for (size_t i = 0; i < size - 1; i++) {
        if (distanceArray[i] < minDistance && i != index) {
            minDistance = distanceArray[i];
            newIndex = i;
        }
    }

    std::cout << "shortest Distance to: " << array[index].getName() << " is " 
        << array[newIndex].getName() << " with " << minDistance << std::endl;

    delete[] distanceArray;
}