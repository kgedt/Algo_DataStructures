//
// Created by magzu on 01.02.2023.
//

using namespace std;

void quicksort(vector<string> &arr, int low, int high) {
    int i = low, j = high;
    string pivot = arr[(low + high) / 2];

    while (i <= j) {
        while (arr[i].length() < pivot.length() || (arr[i].length() == pivot.length() && arr[i] < pivot)) {
            i++;
        }
        while (arr[j].length() > pivot.length() || (arr[j].length() == pivot.length() && arr[j] > pivot)) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (low < j) {
        quicksort(arr, low, j);
    }
    if (i < high) {
        quicksort(arr, i, high);
    }
}

void bigSort(vector<string> &unsorted, int n) {
    quicksort(unsorted, 0, n - 1);
}

#ifndef ALGO_DS_BIGSORT_H
#define ALGO_DS_BIGSORT_H

#endif //ALGO_DS_BIGSORT_H
