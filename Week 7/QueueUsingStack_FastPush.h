#ifndef ALGO_DS_QUEUEUSINGSTACK_FASTPUSH_H
#define ALGO_DS_QUEUEUSINGSTACK_FASTPUSH_H

#include <stack>

using namespace std;

class QueueUsingStack_FastPush { // FRONT() элемент находится внизу стэка, а задний - сверху
                                // можно догадаться, что в этом случае проще будет получать задний элемент
                                // а еще пушить в очередь еще один элемент
private:
    stack<int> s1; // основной стэк, где хранится очередь
    stack<int> s2; // вспомогательный стэк, чтобы проворачивать приколы с push() и pop()

public:
    QueueUsingStack_FastPush() {
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void push(int element) { // так как фронт элемент находится снизу, то задний будет сверху
                            // просто кидаем его наверх стэка
        s1.push(element);
    }

    void pop() {
        if (s1.empty()) {
            cout << "queue is empty!\n";
            return;
        }
        while (s1.size() > 1) { // чтобы удалить из очереди элемент front, нужно дойти до него
                                // он, как я и говорил, находится снизу стэка
                                // поэтому опустошаем(перемещаем временно во 2-й) до последнего элемента
            s2.push(s1.top());
            s1.pop();
        }

        // как только в первом стэке остается один front элемент, то удаляем его к чертям
        s1.pop();

        // возвращем из 2-го все обратно в 1-й стэк
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
        int front_element; // переменная, которую мы вернем как front()

        // в последний раз повторюсь, что front элемент(который первый зашел и первым выйдет)
        // находится снизу стэка
        // значит освобождаем все выше него
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }

        front_element = s1.top(); // дошли до последнего и запоминаем его

        while (!s2.empty()) { // возвращаем все из 2-го обратно в 1-й
            s1.push(s2.top());
            s2.pop();
        }

        return front_element; // возвращаем тот, что запомнили как front element
    }

    int back() { // ну тут попроще. задний элемент всегда сверху, поэтому..
        if (s1.empty()) {
            cout << "stack is empty!\n";
            return NULL;
        }
        return s1.top(); // поэтому возвращаем просто верхний элемент 1-го стэка
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
