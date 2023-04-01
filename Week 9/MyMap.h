#include "hashFunction.h"
#include <iostream>

using namespace std;

template<typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value, const uint64_t &hashCode) :
            key(key), value(value), hashCode(hashCode), next(nullptr) {
    }

    ~HashNode() {
        hashCode = NULL;
        next = nullptr;
    }

    uint64_t getHashCode() const {
        return hashCode;
    }

    K getKey() const {
        return key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        this->value = value;
    }

    HashNode *getNext() const {
        return next;
    }

    void setNext(HashNode *next) {
        this->next = next;
    }

private:
    K key;
    V value;
    int hashCode;
    HashNode *next;
};


template<typename K, typename V>
class HashTable {
public:

    HashTable() {
        table = new HashNode<K, V> *[capacity]();
        size = 0;
    }

    HashTable(const int capacity) {
        table = new HashNode<K, V> *[capacity]();
        this->capacity = capacity;
        size = 0;
    }

    ~HashTable() {
        for (int i = 0; i < capacity; ++i) {
            HashNode<K, V> *cur = table[i];
            while (cur != nullptr) {
                HashNode<K, V> *prev = cur;
                cur = cur->getNext();
                delete prev;
            }
            table[i] = NULL;
        }
        delete[] table;
    }

    bool isContains(const K &key) {
        uint64_t hashCode = hashing(key);
        int index = hashCode % capacity;
        HashNode<K, V> *cur = table[index];

        while (cur != nullptr) {
            if (cur->getHashCode() == hashCode)
                if (cur->getKey() == key)
                    return true;
            cur = cur->getNext();
        }
        return false;
    }

    V get(const K &key) {
        V value;
        uint64_t hashCode = hashing(key);
        int index = hashCode % capacity;
        HashNode<K, V> *cur = table[index];

        while (cur != nullptr) {
            if (cur->getKey() == key) {
                value = cur->getValue();
                return value;
            }
            cur = cur->getNext();
        }
        throw "HASHTABLE_INVALID_KEY";
    }

    void put(const K &key, const V &value) {
        int inc = 1;
        if (isContains(key)) inc = 0;

        uint64_t hashCode = hashing(key);
        int index = hashCode % capacity;
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *cur = table[index];

        while (cur != nullptr && cur->getKey() != key) {
            prev = cur;
            cur = cur->getNext();
        }

        if (cur == nullptr) {
            cur = new HashNode<K, V>(key, value, hashCode);
            if (prev == nullptr) {
                table[index] = cur;
            } else {
                prev->setNext(cur);
            }
        } else {
            cur->setValue(value);
        }
        size += inc;

        if (double (getFilledIndexes()) / double (getCapacity()) > loadFactor || \
            getSize() > 2 * getCapacity()) { rehashing(); }


//        if (double(size) / double(capacity) > loadFactor)
//            rehashing();

    }

    void remove(const K &key) {
        uint64_t hashCode = hashing(key);
        int index = hashCode % capacity;
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *cur = table[index];
        int cnt = 0;

        if (!isContains(key)) throw "HASHTABLE_INVALID_KEY";

        while (cur != nullptr) {
            if (cur->getHashCode() == hashCode)
                if (cur->getKey() == key)
                    break;

            prev = cur;
            cur = cur->getNext();
            cnt++;
        }

        if (cur->getNext() != nullptr) {
            if (cnt)
                prev->setNext(cur->getNext());
            else
                table[index] = cur->getNext();
        } else if (cnt) {
            prev->setNext(nullptr);
        } else {
            table[index] = nullptr;
        }

        delete cur;
        size--;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

private:
    HashNode<K, V> **table;
    int size;
    unsigned int capacity = 16;
    double loadFactor = 0.8;

    HashTable(const int capacity, double loadFactor) {
        table = new HashNode<K, V> *[capacity]();
        this->capacity = capacity;
        size = 0;
        this->loadFactor = loadFactor;
    }

    HashNode<K, V> **getTable() {
        return table;
    }

    HashNode<K, V> **setTable(HashNode<K, V> **another) {
        this->table = another;
    }

    void rehashing() {
        int newCapacity = capacity * 2;
        auto *fullData = new HashTable<K, V>(1, loadFactor = 2);
        HashNode<K, V> *cur;


        for (int i = 0; i < capacity; ++i) {
            cur = table[i];
            while (cur != nullptr) {
                fullData->put(cur->getKey(), cur->getValue());
                cur = cur->getNext();
            }
        }

        auto *newMap = new HashTable<K, V>(newCapacity);
        cur = fullData->table[0];

        while (cur != nullptr) {
            newMap->put(cur->getKey(), cur->getValue());
            cur = cur->getNext();
        }

        this->setTable(newMap->getTable());
        this->capacity = newCapacity;
        this->size = newMap->getSize();
    }

    int getFilledIndexes() {
        int cnt = 0;
        for (int i = 0; i < getCapacity(); ++i)
            if (table[i] != nullptr) cnt++;

        return cnt;
    }
};
