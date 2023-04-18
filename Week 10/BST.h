#include <iostream>
#include <string>

using namespace std;

template<class T>

class BST {
private:
    struct Node {
        T val;
        Node* left;
        Node* right;

        Node(T val) : val(val), left(nullptr), right(nullptr) {
        }

        ~Node() {
            delete left;
            delete right;
        }

        string toString() {
            return val;
        }
    };

    Node* root;

    Node* insert(Node* root, T data) {
        if (!root) {
            return new Node(data);
        }

        if (data < root->val)
            root->left = insert(root->left, data);
        else if (data > root->val)
            root->right = insert(root->right, data);

        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    Node* deleteNode(Node* root, T data) {
        if (!root) {
            return root;
        }

        if (data < root->val) {
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->val) {
            root->right = deleteNode(root->right, data);
        }
        else {
            if (!root->left) {
                Node* temp = root->right;
                root->right = nullptr;
                delete root;
                return temp;
            }
            else if (!root->right) {
                Node* temp = root->left;
                root->left = nullptr;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }

    Node* search(Node* root, T data) {
        if (!root || root->val == data)
            return root;

        if (root->val < data)
            return search(root->right, data);

        return search(root->left, data);
    }

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);
        cout << root->toString() << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;

        cout << root->toString() << " ";
        preorder(root->left);
        preorder(root->right);
    }

    string stringConstruct(Node* node) {
        if (node == nullptr)
            return "";
        string res = "";
        res += stringConstruct(node->left);
        res += node->toString() + ",";
        res += stringConstruct(node->right);
        return res;
    }

public:
    BST() : root(nullptr) {
    }

    void add(T data) {
        root = insert(root, data);
    }

    bool contains(T data) {
        return search(root, data) != nullptr;
    }

    void remove(T data) {
        root = deleteNode(root, data);
    }


    string toString() {
        string result = "[";
        result += stringConstruct(root);
        if (result[result.length() - 1] == ',')
            result.pop_back();
        result += "]";
        return result;
    }

    void printInorder() {
        inorder(root);
    }

    void printPreorder() {
        preorder(root);
    }


};
