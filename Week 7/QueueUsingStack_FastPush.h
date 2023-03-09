#ifndef ALGO_DS_QUEUEUSINGSTACK_FASTPUSH_H
#define ALGO_DS_QUEUEUSINGSTACK_FASTPUSH_H

#include <stack>

using namespace std;

class QueueUsingStack_FastPush {
private:
    stack<int> s1;
    stack<int> s2;

public:
    QueueUsingStack_FastPush() {
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void push(int element) { // front() element at the end of the stack
        s1.push(element);
    }

    void pop() {
        if (s1.empty()) {
            cout << "queue is empty!\n";
            return;
        }
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int front() {
        if (s1.empty()) {
            cout << "queue is empty!\n";
            return NULL;
        }
        int front_element;
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }

        front_element = s1.top();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return front_element;
    }

    int back() {
        if (s1.empty()) {
            cout << "stack is empty!\n";
            return NULL;
        }
        return s1.top();
    }

    void printQueue() {
        cout << "back -> [ ";
        while (!s1.empty()) {
            cout << s1.top() << " ";
            s2.push(s1.top());
            s1.pop();
        }
        cout << "] <- front" << endl;
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
};

#endif //ALGO_DS_QUEUEUSINGSTACK_FASTPUSH_H
