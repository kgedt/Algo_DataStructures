//
// Created by magzu on 03.02.2023.
//
#include <chrono>

using namespace std;

double workTime(void (*sorting_foo)(vector<int>&), vector<int> arr) {
    auto start = chrono::steady_clock::now();
    sorting_foo(arr); // функция принимает вектор не поссылке => с вектором ничего не случится
    auto end = chrono::steady_clock::now();
    auto result = (double) chrono::duration_cast<chrono::microseconds>(end - start).count();
    return result; // результат возвращается в микросекундах
}


#ifndef ALGO_DS_WORKTIME_H
#define ALGO_DS_WORKTIME_H

#endif //ALGO_DS_WORKTIME_H
