#include <iostream>
#include <cmath>
#include <vector>
#include "Week 9/week9.h"

using namespace std;


int main() {
    auto *map = new HashTable<string, string>();
    map->put("Kokshetau", "kokchicago");
    map->put("Kazan", "kzn");
    map->put("Petropavlovsk", "pet");
    map->put("LV", "ac");
    map->put("Taraz", "tar");
    map->put("Astana", "ast");
    map->put("Kostanay", "kos");
    map->put("Satana", "sat");
    map->put("Uralsk", "ura");
    map->put("Burabay", "bur");
    map->put("Shymkent", "shym");
    map->put("Moscow", "mos");
    map->put("Karaganda", "kar");
    map->put("Aksai", "aks");
    map->put("Taldykorgan", "tald");
    map->put("Khulio", "kh");
    map->put("Phuket", "ph");
    map->put("Saint-P", "spb");
    map->put("NewYork", "ny");
    map->put("Los-Angeles", "la");
    map->put("BL", "bl");
    map->put("GA", "ga");
    cout << "CAPACITY: " << map->getCapacity() << endl;

    try {
        cout << map->get("Phuket") << endl;
        map->remove("Astana");
        map->remove("Uralsk");
        cout << map->get("Uralsk") << endl;
    } catch(const char* msg) {
        cout << msg << endl;
    }
    cout << "size = " << map->getSize() << endl;

    return 0;
}