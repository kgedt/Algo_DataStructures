//
// Created by magzu on 01.02.2023.
//

using namespace std;

vector<int> countingSort(vector<int> arr) {
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int counts_size = max - min + 1;
    vector<int> counts(counts_size);

    for (int i = 0; i < arr.size(); i++)
        counts[arr[i]-min]++;

    return counts;
}

#ifndef ALGO_DS_COUNTINGSORT_H
#define ALGO_DS_COUNTINGSORT_H

#endif //ALGO_DS_COUNTINGSORT_H
