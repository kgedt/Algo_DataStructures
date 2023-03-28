#include <iostream>
#include <cmath>
#include <vector>
#include "Week 9/week9.h"

using namespace std;


int main() {
    //HashMap<string, string> map(20);
    auto *map = new HashMap<string, string>(16);
    cout << "CAPACITY = " << map->getCapacity() << endl;
    map->put("Kokshetau", "kokchicago");
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
    cout << "CAPACITY = " << map->getCapacity() << endl;
    map->put("Khuli", "kh");
    map->put("Phuket", "ph");
    map->put("Saint-P", "spb");
    map->put("saint-p", "spb");
    map->put("NewYork", "ny");
    map->put("newyork", "ny");
    map->put("Los-Angeles", "la");

    try {
        cout << map->get("Phuket") << endl;
        //map->remove("Astana");
        cout << map->get("Los-Angeles") << endl;
    } catch(const char* msg) {
        cout << msg << endl;
    }
    cout << "size = " << map->getSize() << endl;

    return 0;
}