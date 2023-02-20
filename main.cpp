#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "./Week 1/week1.h"
#include "./Week 2/week2.h"
#include "./Week 3/week3.h"
#include "./Week 4/week4.h"

using namespace std;

int main() {
    int arr[10] = {9, 2, 1, 3, 4, 10, 8, 6, 7, 5};
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    } cout << endl;
    myQuickSort(arr, 0, 9);
    for (int i = 0; i < 10; ++i) {
        cout << arr[i] << " ";
    }

//    srand(time(NULL));
//    vector<int> arr(20);
//    for (int i = 0; i < arr.size(); ++i) {
//        arr[i] = rand()%100;
//    }
//    printArray(arr);
//    cout << endl;
//    myQuickSort(arr, 1, arr.size());
//    printArray(arr);
//    void (*mergeSortFoo)(vector<int> &arr, int begin, int end);
//    void (*sortFoo)(vector<int> &arr);
//
//    mergeSortFoo = myMergeSort;
//    double time = mergeWorkTime(mergeSortFoo, arr, 0, arr.size() - 1);
//    cout << "merge work time = " << (double)time/1000 << endl << endl;
//
//    sortFoo = insertionSort;
//    double time2 = workTime(sortFoo, arr);
//    cout << "insertion work time = " << (double)time2/1000 << endl << endl;

    //myMergeSort(arr, 0, arr.size() - 1);
    //printArray(arr); cout << endl;

    return 0;
}