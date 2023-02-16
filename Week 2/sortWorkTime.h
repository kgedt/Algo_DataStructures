//
// Created by magzu on 03.02.2023.
//
#include <chrono>

using namespace std;

double mergeWorkTime(void (*sorting_foo)(vector<int>&, int begin, int end), vector<int> arr, int left, int right) {
    auto start = chrono::steady_clock::now();
    sorting_foo(arr, left, right); // функция принимает вектор не по ссылке => с вектором ничего не случится
    auto end = chrono::steady_clock::now();
    auto result = (double) chrono::duration_cast<chrono::milliseconds >(end - start).count();
//    cout << "MERGE SORT: " << endl;
//    for (int i = 0; i < arr.size(); ++i) {
//        cout << arr[i] << " ";
//    } cout << endl << endl;
    return result; // результат возвращается в микросекундах
}

double workTime(void (*sorting_foo)(vector<int>&), vector<int> arr) {
    auto start = chrono::steady_clock::now();
    sorting_foo(arr); // функция принимает вектор не по ссылке => с вектором ничего не случится
    auto end = chrono::steady_clock::now();
    auto result = (double) chrono::duration_cast<chrono::milliseconds >(end - start).count();
//    cout << "SELECTION SORT: " << endl;
//    for (int i = 0; i < arr.size(); ++i) {
//        cout << arr[i] << " ";
//    } cout << endl << endl;
    return result; // результат возвращается в микросекундах
}


#ifndef ALGO_DS_WORKTIME_H
#define ALGO_DS_WORKTIME_H

#endif //ALGO_DS_WORKTIME_H
