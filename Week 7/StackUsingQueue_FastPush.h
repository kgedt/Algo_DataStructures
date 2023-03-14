#ifndef ALGO_DS_STACKUSINGQUEUE_FASTPUSH_H
#define ALGO_DS_STACKUSINGQUEUE_FASTPUSH_H

#include <queue>

class StackUsingQueue_FastPush {
    // push -> O(1)
private:
    queue<int> q1;
    queue<int> q2;

public:
    StackUsingQueue_FastPush() {
        this->q1 = queue<int>();
        this->q2 = queue<int>();
    }

    void push(int element) {
        q1.push(element);
    }

    void pop() {
        if (q1.size() == 0) return;
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int top() {
        if (q1.empty()) {
            cout << "stack is empty!\n";
            return NULL;
        }
        return q1.back();
    }

    int size() {
        return q1.size();
    }

    void printStack() {
        cout << "[";
        while (!q1.empty()) {
            cout << q1.front() << ",";
            q2.push(q1.front());
            q1.pop();
        }
        cout << "]\n";

        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
};

#endif //ALGO_DS_STACKUSINGQUEUE_FASTPUSH_H
