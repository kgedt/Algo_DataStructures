#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include "./Week 3/min_abs_diff.h"
#include "./Week 3/min_unfairness.h"

using namespace std;

int main() {
    int n, k=2;
    vector<int> arr = {10, 100, 300, 200, 1000, 20, 30};
    cout << min_unfariness(arr, 3);

    return 0;
}