#include "location.hpp"

class Map{
private:
    Location* array;
    int size;
    int capacity;

    void resize(int newCapacity);
public:
    Map();
    Map(const int initCapacity);
    Map(const Map& other); // copy constructor
    Map& operator=(const Map& other);
    ~Map();

    void copyFrom(const Map& other);
    void addToMap(const Location& location);

    void printMap() const;
    void distance(const int first, const int second);
    void getShortestDistance(const int index);
};