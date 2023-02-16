#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "./Week 4/myMergeSort.h"
#include "./Week 2/sortWorkTime.h"
#include "./Week 2/selectionSort.h"
#include "./Week 2/insertionSort.h"

using namespace std;

int main() {
    srand(time(NULL));
    vector<int> arr(100000);
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = rand()%100;
    }
    void (*mergeSortFoo)(vector<int> &arr, int begin, int end);
    void (*sortFoo)(vector<int> &arr);

    mergeSortFoo = myMergeSort;
    double time = mergeWorkTime(mergeSortFoo, arr, 0, arr.size() - 1);
    cout << "merge work time = " << (double)time/1000 << endl << endl;

    sortFoo = insertionSort;
    double time2 = workTime(sortFoo, arr);
    cout << "insertion work time = " << (double)time2/1000 << endl << endl;

    //myMergeSort(arr, 0, arr.size() - 1);
    //printArray(arr); cout << endl;

    return 0;
}