//
// Created by magzu on 03.02.2023.
//
using namespace std;

void bubbleSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i)
        for (int j = 1; j < arr.size() - i; ++j)
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
}


#ifndef ALGO_DS_BUUBLESORT_H
#define ALGO_DS_BUUBLESORT_H

#endif //ALGO_DS_BUUBLESORT_H
