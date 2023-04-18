
using namespace std;

string to_string(string any) {
    return any;
}

string to_string(char any) {
    string res = &any;
    res = res[0];
    return res;
}


template<typename T>
class AVL {
private:
    struct Node {
        T val;
        int height;
        Node *left;
        Node *right;

        Node(T val) {
            this->val = val;
            height = 1;
            left = nullptr;
            right = nullptr;
        }

        ~Node() {

        }

        string toString() {
            return to_string(this->val);
        }
    };

    Node *root;


    string stringConstruct(Node *node) {
        if (node == nullptr)
            return "";
        string res = "";
        res += stringConstruct(node->left);
        res += node->toString() + ",";
        res += stringConstruct(node->right);
        return res;
    }

    string toString() {
        string result = "[";
        result += stringConstruct(root);
        if (result[result.length() - 1] == ',')
            result.pop_back();
        result += "]";
        return result;
    }

    int getHeight(Node *node) {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceIndex(Node *node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *rightRotate(Node *x) {
        Node *y = x->left;
        Node *temp = y->right;

        y->right = x;
        x->left = temp;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }


    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }


    Node *insert(Node *root, T data) {
        if (root == nullptr) {
            root = new Node(data);
            return root;
        }

        if (data < root->val)
            root->left = insert(root->left, data);
        else if (data > root->val)
            root->right = insert(root->right, data);
        else
            return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalanceIndex(root);

        if (balance > 1 && data < root->left->val)
            return rightRotate(root);
        if (balance < -1 && data > root->right->val)
            return leftRotate(root);
        if (balance > 1 && data > root->left->val) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && data < root->right->val) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node *search(Node *root, T data) {
        if (!root || root->val == data)
            return root;

        if (root->val < data)
            return search(root->right, data);

        return search(root->left, data);
    }

    Node *minValueNode(Node *node) {
        Node *current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *root, T data) {
        if (!root) {
            return root;
        }

        if (data < root->val) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->val) {
            root->right = deleteNode(root->right, data);
        } else {
            if (!root->left) {
                Node *temp = root->right;
                root->right = nullptr;
                delete root;
                return temp;
            } else if (!root->right) {
                Node *temp = root->left;
                root->left = nullptr;
                delete root;
                return temp;
            }
            Node *temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->val << endl;
        inorder(root->right);
    }

    void preorder(Node *root) {
        if (root == nullptr)
            return;
        cout << root->val << endl;
        preorder(root->left);
        preorder(root->right);
    }

public:

    AVL() {
        root = nullptr;
    }

    void add(T data) {
        root = insert(root, data);
    }

    bool contains(T data) {
        return search(root, data) != nullptr;
    }

    void remove(T data) {
        deleteNode(root, data);
    }

    void printInorder() {
        inorder(root);
    }

    void printPreorder() {
        preorder(root);
    }

// overload <<
    friend ostream &operator<<(ostream &out, AVL<T> *avl) {
        cout << avl->toString() << endl;
        return out;
    }

};

