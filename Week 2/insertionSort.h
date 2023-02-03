//
// Created by magzu on 03.02.2023.
//
using namespace std;

void insertionSort(vector<int> &arr) {
    for(int i = 1; i < arr.size(); i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
}

#ifndef ALGO_DS_INSERTIONSORT_H
#define ALGO_DS_INSERTIONSORT_H

#endif //ALGO_DS_INSERTIONSORT_H
