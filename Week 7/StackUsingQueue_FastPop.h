#ifndef ALGO_DS_STACKUSINGQUEUE_FASTPOP_H
#define ALGO_DS_STACKUSINGQUEUE_FASTPOP_H

#include <queue>

class StackUsingQueue_FastPop {
    // pop -> O(1)
private:
    queue<int> q1;
    queue<int> q2;

public:
    StackUsingQueue_FastPop() {
        this->q1 = queue<int>();
        this->q2 = queue<int>();
    }

    void push(int element) {
        if (q1.size() == 0) {
            q1.push(element);
            return;
        }
        q2.push(element);
        while (q1.size() != 0) {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp;

        temp = q2;
        q2 = q1;
        q1 = temp;
    }

    void pop() {
        q1.pop();
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
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "[";
        while (!q2.empty()) {
            q1.push(q2.front());
            cout << q1.back() << ",";
            q2.pop();
        }
        cout << "]\n";
    }
};

#endif //ALGO_DS_STACKUSINGQUEUE_FASTPOP_H
