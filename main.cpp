#include <iostream>
#include <cmath>
#include <vector>
#include "Week 11/AVL.h"

using namespace std;

int main() {
    AVL<int> *tree = new AVL<int>();

    tree->add(5);
    tree->add(4);
    tree->add(3);
    tree->add(2);
    tree->add(1);

    cout << tree << endl;

    cout << "3 is contains in tree: " << tree->contains(3) << endl;
    cout << "2 is contains in tree: " << tree->contains(2) << endl;

    tree->remove(3);
    cout << "removed 3" << endl;

    cout << "3 is contains in tree: " << tree->contains(3) << endl;

    cout << tree << endl;

    AVL<string> *string_tree = new AVL<string>();

    string_tree->add("B");
    string_tree->add("C");
    string_tree->add("A");
    string_tree->add("D");
    string_tree->add("F");

    cout << string_tree << endl;

    AVL<char> *char_tree = new AVL<char>();

    char_tree->add('v');
    char_tree->add('d');
    char_tree->add('c');
    char_tree->add('b');

    cout << char_tree << endl;


    return 0;
}