//
// Created by magzu on 14.02.2023.
//

using namespace std;

void printArray(vector<int> arr) {
    for (auto val: arr)
        cout << val << " ";
}

void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> leftArr(mid - left + 1);
    vector<int> rightArr(right - mid);

    for (int i = 0; i < leftArr.size(); ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < rightArr.size(); ++i)
        rightArr[i] = arr[mid + i + 1];

    int indLeft = 0, indRight = 0, indMerged = left;

    while (indLeft < leftArr.size() && indRight < rightArr.size()) {
        if (leftArr[indLeft] <= rightArr[indRight]) {
            arr[indMerged] = leftArr[indLeft];
            indLeft++;
        }
        else {
            arr[indMerged] = rightArr[indRight];
            indRight++;
        }
        indMerged++;
    }
    while (indLeft < leftArr.size()) {
        arr[indMerged] = leftArr[indLeft];
        indLeft++;
        indMerged++;
    }

    while (indRight < rightArr.size()) {
        arr[indMerged] = rightArr[indRight];
        indRight++;
        indMerged++;
    }
}

//void merge(vector<int> &arr, int left, int mid, int right) {
//    for (int i = left; i <= right; i++)
//        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
//            swap(arr[j - 1], arr[j]);
//}

void myMergeSort(vector<int> &arr, int begin, int end) {
    if (begin >= end) return;
    int mid = begin + (end - begin) / 2;
    myMergeSort(arr, begin, mid);
    myMergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

#ifndef ALGO_DS_MYMERGESORT_H
#define ALGO_DS_MYMERGESORT_H

#endif //ALGO_DS_MYMERGESORT_H
