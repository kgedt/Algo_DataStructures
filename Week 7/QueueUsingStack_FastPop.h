#ifndef ALGO_DS_QUEUEUSINGSTACK_FASTPOP_H
#define ALGO_DS_QUEUEUSINGSTACK_FASTPOP_H

#include <stack>

using namespace std;

class QueueUsingStack_FastPop { // В ЭТОЙ ОЧЕРЕДИ FRONT() ЭЛЕМЕНТ НАХОДИТСЯ СВЕРХУ СТЭКА. BACK() - СНИЗУ
private:
    stack<int> s1; // основной стэк, где хранится очередь
    stack<int> s2; // вспомогательный стэк, чтобы проворачивать приколы с push() и pop()

public:
    QueueUsingStack_FastPop() {
        s1 = stack<int>();
        s2 = stack<int>();
    }

    void push(int element) {
        if (s1.empty()) { // если стэк пустой, просто пушаем
            s1.push(element);
            return;
        }

        // самый первый элемент находится сверху стэка
        // следовательно, последний нужно добавлять в конец стэка

        while (!s1.empty()) { // для этого перемещаем все элементы сначала во 2 стэк
            s2.push(s1.top());
            s1.pop();
        }

        s2.push(element); // добавляем наверх 2 стэка элемент, который мы хотим добавить
        // при добавлении элемента наверх 2 стэка
        // он окажется последним в 1 стэке => последним в queue

        while (!s2.empty()) { // как только добавили элемент, который хотели, перемещаем все в 1-й
            s1.push(s2.top());
            s2.pop();
        }
    }

    void pop() {
        s1.pop(); // поскольку front элемент находится сверху стэка
        // достаточно удалить его и все
    }

    int front() { // FIFO (первый вошел, первый вышел. как в трубу короче)
        // так как первый элемент очереди сверху стэка, то достаточно вывести stack.top()

        if (s1.empty()) { // если стэк пустой, то и очередь пустая
            cout << "stack is empty!\n";
            return NULL;
        }
        return s1.top(); //
    }

    int back() { // задний элемент находится снизу стэка
        // нужно сначала освободить все вышестоящие элементы, чтобы дойти до нижнего

        if (s1.empty()) {
            cout << "stack is empty!\n";
            return NULL;
        }

        int back_element; // запоминаем последний элемент очереди, потому что..
        // нам нужно еще вернуть все элементы в 1 стэк, который и является по сути очередью

        while (s1.size() > 1) { // перемещаем все элементы во 2-й стэк, пока не дойдем до нижнего
            s2.push(s1.top());
            s1.pop();
        }

        back_element = s1.top(); // дошли до низа стэка и записываем в переменную

        while (!s2.empty()) { // возвращаем всё из 2-го стэка в 1-й(ПОВТОРЮСЬ: 1-й СТЭК И ЕСТЬ НАША ОЧЕРЕДЬ ПО СУТИ)
            s1.push(s2.top());
            s2.pop();
        }

        return back_element; // ну и собсна возвращаем тот задний элемент, который запомнили
    }

    void printQueue() { // вывод очереди
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
