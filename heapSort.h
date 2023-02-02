//
// Created by magzu on 01.02.2023.
//

using namespace std;

void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        swap(arr[left], arr[largest]);
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        swap(arr[right], arr[largest]);
        largest = right;
    }

    if (i != largest) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n-1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

#ifndef ALGO_DS_HEAPSORT_H
#define ALGO_DS_HEAPSORT_H

#endif //ALGO_DS_HEAPSORT_H
