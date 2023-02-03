//
// Created by magzu on 03.02.2023.
//

using namespace std;

void selectionSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int ind_max = 0;

        for (int j = 0; j < arr.size() - i; ++j)
            if (arr[j] > arr[ind_max])
                ind_max = j;

        swap(arr[ind_max], arr[arr.size() - i - 1]);
    }
}

#ifndef ALGO_DS_SELECTIONSORT_H
#define ALGO_DS_SELECTIONSORT_H

#endif //ALGO_DS_SELECTIONSORT_H
