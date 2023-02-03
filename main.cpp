#include <iostream>
#include <vector>
#include <string>

#include "./Week 2/bubbleSort.h"
#include "./Week 2/insertionSort.h"
#include "./Week 2/selectionSort.h"
#include "./Week 2/sortWorkTime.h"

using namespace std;

void printArray(vector<int> arr); // вывод элементов вектора

int main() {
    vector<int> arr(30);
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = rand() % 1000 + 1;

    // декларируем указатель на функцию с определенным типом, параметрами под названием 'sort_function'
    void (*sort_function)(vector<int>&);

    sort_function = bubbleSort; // присваиваем переменной указатель на функцию 'bubbleSort'
    double time = workTime(sort_function, arr);
    cout << "work time = " << time << " microseconds" << endl;

    sort_function = selectionSort; // то же, что и с пузырьком и так далее..
    time = workTime(sort_function, arr);
    cout << "work time = " << time << " microseconds" << endl;

    sort_function = insertionSort;
    time = workTime(sort_function, arr);
    cout << "work time = " << time << " microseconds" << endl;

    return 0;
}

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl << endl;
}