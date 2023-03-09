#include <iostream>
#include <vector>
#include "./Week 1/week1.h"
#include "./Week 2/week2.h"
#include "./Week 3/week3.h"
#include "./Week 4/week4.h"
#include "./Week 7/week7.h"
#include "heapSort.h"

using namespace std;

int main() {
    QueueUsingStack_FastPush q_push;
    QueueUsingStack_FastPop q_pop;
    for (int i = 1; i < 100; ++i) {
        q_push.push(i);
        q_pop.push(i);
    }

    auto start = chrono::steady_clock::now();
    q_pop.pop();
    auto end = chrono::steady_clock::now();
    auto qpop_pop_time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();

    start = chrono::steady_clock::now();
    q_pop.push(5);
    end = chrono::steady_clock::now();
    auto qpop_push_time = chrono::duration_cast<chrono::nanoseconds>(end-start).count();

    cout << "queue(fast pop) pop time = " << qpop_pop_time << " nanosec" << endl;
    cout << "queue(fast pop) push time = " << qpop_push_time << " nanosec" << endl;

    return 0;
}