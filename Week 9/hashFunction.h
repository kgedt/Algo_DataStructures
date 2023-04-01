//
// Created by magzu on 27.03.2023.
//

#ifndef ALGO_DS_HASHFUNCTION_H
#define ALGO_DS_HASHFUNCTION_H

#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <typeinfo>

using namespace std;

void toLowerCase(string &str) {
    for (int i = 0; i < str.size(); ++i)
        if (isalpha(str[i]) && isupper(str[i]))
            str[i] = tolower(str[i]);
}

uint64_t hashing(const string &line) {
    string str = line;

    uint64_t hashCode = 0;
    //toLowerCase(str);

    for (int i = 0; i < line.size(); ++i) {
        hashCode += pow(4, i) * static_cast<int>(str[i]);
    }


    return hashCode;
}

uint64_t hashing(const int &num) {
    return num;
}

uint64_t hashing(const double &num) {
    return static_cast<uint64_t>(num);
}

uint64_t hashing(const float &num) {
    return static_cast<uint64_t>(num);
}

uint64_t hashing(const char &c) {
    return static_cast<uint64_t>(c);
}

template<typename T>
uint64_t hashing(const vector<T> &v) {
    if (v.size() == 0)
        return hashing(v.size());
    return hashing(v.size()) + hashing(v.front());
}


#endif //ALGO_DS_HASHFUNCTION_H
