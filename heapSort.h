//
// Created by magzu on 01.02.2023.
//

using namespace std;

//template<class T>
//class Tree {
//public:
//    vector<int> arr;
//    vector<T> nodes;
//
//    class TreeNode {
//    private:
//        int largest_index;
//        int left_index;
//        int right_index;
//    public:
//        TreeNode(int largest_index) {
//            this->largest_index = largest_index;
//            this->left_index = 2 * largest_index + 1;
//            this->right_index = 2 * largest_index + 1;
//        }
//    };
//
//    Tree(vector<int> arr) {
//        this->arr = arr;
//    }
//
//    void inTreeNode() {
//        for (int i = arr.size() / 2 - 1; i >= 0; --i) {
//            TreeNode newNode = new TreeNode(i);
//            nodes.push_back();
//        }
//    }
//
//    void heapify(vector<int> &arr, int n, int i) {
//        int largest = i;
//        int left = 2 * i + 1;
//        int right = 2 * i + 2;
//
//        if (left < n && arr[left] > arr[largest]) {
//            swap(arr[left], arr[largest]);
//            largest = left;
//        }
//        if (right < n && arr[right] > arr[largest]) {
//            swap(arr[right], arr[largest]);
//            largest = right;
//        }
//
//        if (i != largest) {
//            swap(arr[i], arr[largest]);
//            heapify(arr, n, largest);
//        }
//    }
//
//    void heapSort(vector<int> &arr) {
//        int n = arr.size();
//        for (int i = n / 2 - 1; i >= 0; --i)
//            heapify(arr, n, i);
//
//        for (int i = n - 1; i >= 0; --i) {
//            swap(arr[i], arr[0]);
//            heapify(arr, i, 0);
//        }
//    }
//};


void heapify(vector<int> &arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        swap(arr[left], arr[largest]);
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        swap(arr[right], arr[largest]);
        largest = right;
    }

    if (i != largest) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; --i) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

#ifndef ALGO_DS_HEAPSORT_H
#define ALGO_DS_HEAPSORT_H

#endif //ALGO_DS_HEAPSORT_H
