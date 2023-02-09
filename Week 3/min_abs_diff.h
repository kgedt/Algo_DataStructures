//
// Created by magzu on 08.02.2023.
//
#include <algorithm>
using namespace std;

int min_abs_diff(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int min_abs = abs(arr[0] - arr[1]);
    int current;

    for (int i = 2; i < arr.size(); ++i) {
        current = abs(arr[i] - arr[i-1]);
        if (current < min_abs)
            min_abs = current;
    }

    return min_abs;
}


#ifndef ALGO_DS_MIN_ABS_DIFF_H
#define ALGO_DS_MIN_ABS_DIFF_H

#endif //ALGO_DS_MIN_ABS_DIFF_H
