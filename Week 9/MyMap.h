#include "hashFunction.h"
#include <iostream>

using namespace std;

template<typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value, const uint64_t &hashcode) :
            key(key), value(value), hashcode(hashcode), next(nullptr) {
    }

    uint64_t getHashcode() const {
        return hashcode;
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
    int hashcode;
    HashNode *next;
};



template<typename K, typename V>
class HashMap {
public:

    HashMap() {
        table = new HashNode<K, V> *[capacity]();
        size = 0;
    }

    HashMap(const int capacity) {
        table = new HashNode<K, V> *[capacity]();
        this->capacity = capacity;
        size = 0;
    }

    ~HashMap() {
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
        uint64_t hashcode = hashing(key);
        int index = hashcode % capacity;
        HashNode<K, V> *cur = table[index];

        while (cur != nullptr) {
            if (cur->getHashcode() == hashcode)
                if (cur->getKey() == key)
                    return true;
            cur = cur->getNext();
        }
        return false;
    }

    V get(const K &key) {
        V value;
        uint64_t hashcode = hashing(key);
        int index = hashcode % capacity;
        HashNode<K, V> *cur = table[index];

        while (cur != nullptr) {
            if (cur->getKey() == key) {
                value = cur->getValue();
                return value;
            }
            cur = cur->getNext();
        }
        throw "HASHMAP_INVALID_KEY";
    }

    void put(const K &key, const V &value) {
        int inc = 1;
        if (isContains(key)) inc = 0;

        uint64_t hashcode = hashing(key);
        int index = hashcode % capacity;
        //cout << "key: " << key << ", hashcode: " << hashcode << ", index: " << index << endl;
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *cur = table[index];

        while (cur != nullptr && cur->getKey() != key) {
            prev = cur;
            cur = cur->getNext();
        }

        if (cur == nullptr) {
            cur = new HashNode<K, V>(key, value, hashcode);
            if (prev == nullptr) {
                table[index] = cur;
            } else {
                prev->setNext(cur);
            }
        } else {
            cur->setValue(value);
        }
        size += inc;

        if (double(size) / double(capacity) > loadFactor) {
            rehashing();
        }
    }

    void remove(const K &key) {
        uint64_t hashcode = hashing(key);
        int index = hashcode % capacity;
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *cur = table[index];

        while (cur != nullptr) {
            if (cur->getHashcode() == hashcode)
                if (cur->getKey() == key)
                    break;

            prev = cur;
            cur = cur->getNext();
        }

        if (cur == nullptr) {
            throw "HASHMAP_INVALID_KEY";
        } else {
            if (cur->getNext() != nullptr) {
                prev->setNext(cur->getNext());
            } else {
                prev->setNext(nullptr);
            }
            delete cur;
            size--;
        }
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
    int capacity = 16;
    double loadFactor = 0.75;

    HashMap(const int capacity, const double loadFactor) {
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
        auto* fullData = new HashMap<K, V>(1, getSize());
        HashNode<K, V> *cur;


        for (int i = 0; i < capacity; ++i) {
            cur = table[i];
            while (cur != nullptr) {
                fullData->put(cur->getKey(), cur->getValue());
                cur = cur->getNext();
            }
        }

        auto* newMap = new HashMap<K, V>(newCapacity);

        cur = fullData->table[0];

        while (cur != nullptr) {
            newMap->put(cur->getKey(), cur->getValue());
            cur = cur->getNext();
        }

        this->setTable(newMap->getTable());
        this->capacity = newCapacity;
        this->size = newMap->getSize();

    }


};
