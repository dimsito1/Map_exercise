#include "location.hpp"
#include "map.hpp"

int main() {
    Location Burgas("Burgas", 10.3 , 52.3);
    Location Tsarevo("Tsarevo", 32.3 , 42.5);
    Location Sofia("Sofia", 130, 32.6);
    Location Paris("Paris" , 3123.5, 321.4);

    Paris.printLocation();
    Map firstMap;
    Map secondMap(1);
    secondMap.addToMap(Burgas);
    secondMap.addToMap(Tsarevo);
    secondMap.addToMap(Sofia);
    secondMap.addToMap(Paris);
    secondMap.printMap();
    secondMap.getShortestDistance(3);
    secondMap.distance(0 ,1);
    

    return 0;
}