#include <iostream>
#include <vector>
#include <string>
#include "./Week 1/bigSort.h"
#include "./Week 1/countingSort.h"
#include "./Week 1/insertionSortAnalysis.h"
#include "heapSort.h"

using namespace std;

int main() {
    vector<int> arr = {5, 1, 2, 4, 3};
    heapSort(arr);
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
