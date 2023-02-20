//
// Created by magzu on 18.02.2023.
//

using namespace std;
#include <iostream>
using namespace std;

int doublePartition(int* arr, int left, int right, int* lp);

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void doublePivotQuickSort(int* arr, int start, int end)
{
    if (start < end) {
        int left_pivot, right_pivot;
        right_pivot = doublePartition(arr, start, end, &left_pivot);
        doublePivotQuickSort(arr, start, left_pivot - 1);
        doublePivotQuickSort(arr, left_pivot + 1, right_pivot - 1);
        doublePivotQuickSort(arr, right_pivot + 1, end);
    }
}

int doublePartition(int* arr, int left, int right, int* lp)
{
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);

    int k = left + 1;
    int r = right - 1, l = left + 1;
    int left_pivot = arr[left], right_pivot = arr[right];

    while (l <= r) {
        if (arr[l] < left_pivot) {
            swap(arr[l], arr[k]);
            k++;
        }
        else if (arr[l] >= right_pivot) {
            while (arr[r] > right_pivot && l < r) r--;
            swap(arr[l], arr[r]);
            r--;
            if (arr[l] < left_pivot) {
                swap(arr[l], arr[k]);
                k++;
            }
        }
        l++;
    }
    k--;
    r++;

    swap(arr[left], arr[k]);
    swap(arr[right], arr[r]);

    *lp = k;

    return r;
}



#ifndef ALGO_DS_DOUBLEPIVOTQUICKSORT_H
#define ALGO_DS_DOUBLEPIVOTQUICKSORT_H

#endif //ALGO_DS_DOUBLEPIVOTQUICKSORT_H
