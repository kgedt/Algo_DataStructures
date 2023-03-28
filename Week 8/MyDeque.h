//
// Created by magzu on 25.03.2023.
//

using namespace std;

template<typename T>
class MyLinkedList {
private:
    class Node {
    public:
        T data;
        Node *next;
        Node *prev;

        Node(T data, Node *next, Node *prev) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }

    };

    int size;
    Node *head;
    Node *tail;

public:
    MyLinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    int getSize() {
        return this->size;
    }

    void add_front(T element) {
        if (head == nullptr) {
            head = new Node(element, nullptr, nullptr);
            tail = head;
        } else {
            tail->next = new Node(element, nullptr, tail);
            tail = tail->next;
        }
        size++;
    }

    void add_back(T element) {
        if (head == nullptr) {
            head = new Node(element, nullptr, nullptr);
            tail = head;
        } else {
            Node *current = tail;
            tail->next = new Node(element, nullptr, tail);
            tail = tail->next;
        }
        size++;
    }


    void remove(int idx) {
        if (getSize() == 1) {
            head = nullptr;
            tail = nullptr;
            size--;
            return;
        }

        if (idx == 0) {
            head = head->next;
            head->prev = nullptr;
            size--;
            return;
        } else if (idx == size - 1) {
            tail = tail->prev;
            tail->next = nullptr;
            size--;
            return;
        }

        if (idx >= size) {
            cout << "out_of_range";
            return;
        } else if (idx <= size / 2) {
            int cnt = 0;
            Node *cur = head;
            while (cnt != idx) {
                cur = cur->next;
                cnt++;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        } else {
            idx = size - 1 - idx;
            int cnt = 0;
            Node* cur = tail;
            while (cnt != idx) {
                cur = tail->prev;
                cnt++;
            }
            cur->next->prev = cur->prev;
            cur->prev->next = cur->next;
        }
        size--;
    }

    T get_head() {
        return head->data;
    }

    T get_tail() {
        return tail->data;
    }

    bool isEmpty() {
        if (getSize() <= 0) return true;
        return false;
    }

};

template<typename T>
class MyDeque {
private:
    MyLinkedList<T> *ll;

public:
    MyDeque() {
        ll = new MyLinkedList<T>;
    }

    void push_back(T element) {
        ll->add_back(element);
    }

    void pop_back() {
        ll->remove(ll->getSize() - 1);
    }

    void push_front(T element) {
        ll->add_front(element);
    }

    void pop_front() {
        ll->remove(0);
    }

    bool is_empty() {
        return ll->isEmpty();
    }

    void clear() {
        while (!ll->isEmpty()) {
            ll->remove(0);
        }
    }

    void print() {
        MyLinkedList<T> *temp = new MyLinkedList<T>;
        while (!is_empty()) {
            cout << ll->get_head() << " ";
            temp->add_front(ll->get_head());
            this->pop_front();
        }
        cout << endl;
        ll = temp;
    }

};

#ifndef ALGO_DS_MYDEQUE_H
#define ALGO_DS_MYDEQUE_H

#endif //ALGO_DS_MYDEQUE_H
