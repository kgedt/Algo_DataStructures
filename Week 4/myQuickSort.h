//
// Created by magzu on 18.02.2023.
//
using namespace std;

void myQuickSort(int *arr, int left, int right) {
    if (left > right) return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) swap(arr[i], arr[j]);
    }
    myQuickSort(arr, left, j);
    myQuickSort(arr, i, right);
}

#ifndef ALGO_DS_MYQUICKSORT_H
#define ALGO_DS_MYQUICKSORT_H

#endif //ALGO_DS_MYQUICKSORT_H
