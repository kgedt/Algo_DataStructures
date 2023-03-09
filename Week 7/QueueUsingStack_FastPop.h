#ifndef ALGO_DS_QUEUEUSINGSTACK_FASTPOP_H
#define ALGO_DS_QUEUEUSINGSTACK_FASTPOP_H

#include <stack>

using namespace std;

class QueueUsingStack_FastPop {
private:
    stack<int> s1;
    stack<int> s2;

public:
    QueueUsingStack_FastPop() {
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void push(int element) { // front() element at the top of the stack
        if (s1.empty()) {
            s1.push(element);
            return;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s2.push(element);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop();
    }

    int front() {
        if (s1.empty()) {
            cout << "stack is empty!\n";
            return NULL;
        }
        return s1.top();
    }

    int back() {
        if (s1.empty()) {
            cout << "stack is empty!\n";
            return NULL;
        }
        int back_element;
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }

        back_element = s1.top();

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return back_element;
    }

    void printQueue() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        cout << "back -> [ ";
        while (!s2.empty()) {
            cout << s2.top() << " ";
            s1.push(s2.top());
            s2.pop();
        }
        cout << "] <- front" << endl;
    }
};

#endif //ALGO_DS_QUEUEUSINGSTACK_FASTPOP_H
