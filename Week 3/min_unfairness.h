//
// Created by magzu on 08.02.2023.
//
#include <algorithm>

using namespace std;

int min_unfariness(vector<int> arr, int k) {
    sort(arr.begin(), arr.end());
    int result = arr[k - 1] - arr[0], current;

    for (int i = 0; i < arr.size() - k + 1; ++i) {
        current = arr[k + i - 1] - arr[i];
        if (current < result)
            result = current;
    }

    return result;
}

#ifndef ALGO_DS_MIN_UNFAIRNESS_H
#define ALGO_DS_MIN_UNFAIRNESS_H

#endif //ALGO_DS_MIN_UNFAIRNESS_H
