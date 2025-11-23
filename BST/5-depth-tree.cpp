#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
public:
    Node* root;
    BST() {
        root = nullptr;
    }

    Node* insert(Node* root, int value) {
        if (root == nullptr)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printInorder(Node* node) {
        if (node == nullptr)
            return;

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }

    void display() {
        printInorder(root);
    }

    // ---- Depth function added ----
    int depth(Node* node, int key, int level) {
        if (node == nullptr)
            return -1; // key not found

        if (node->data == key)
            return level;

        if (key < node->data)
            return depth(node->left, key, level + 1);
        else
            return depth(node->right, key, level + 1);
    }

    int getDepth(int key) {
        return depth(root, key, 0);
    }
};

int main() {
    int numberOfElements, element;
    cout << "Please enter the number of elements in BST: ";
    cin >> numberOfElements;

    BST tree;

    for (int i = 0; i < numberOfElements; i++) {
        cout << "Please enter the element: ";
        cin >> element;
        tree.insert(element);
    }

    cout << "BST Inorder Traversal: ";
    tree.display();

    int key;
    cout << "\nEnter the value to find its depth: ";
    cin >> key;

    int d = tree.getDepth(key);

    if (d == -1)
        cout << "Element not found in BST";
    else
        cout << "Depth of " << key << " is: " << d;

    return 0;
}
