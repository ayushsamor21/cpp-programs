#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* left;

    Node (int value) {
        data = value;
        right = left = nullptr;
    }
};

class BST {
private: 
    Node* root;

    // Helper insert function
    Node* insert (Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    void printInorder(Node* node) {
        if (node == nullptr)
            return;

        printInorder(node->left);
        cout << node->data << "->";
        printInorder(node->right);
    }

public:
    BST () {
        root = nullptr;
    }

    // called from main
    void insert (int value) {
        root = insert(root, value);
    }

    void display() {
        printInorder(root);
    }
};

int main () {
    int numberOfElements, element;
    cout << "Please enter the number of elements: ";
    cin >> numberOfElements;

    BST tree;

    for (int i = 0; i < numberOfElements; i++) {
        cout << "Please enter the elements: ";
        cin >> element;
        tree.insert(element);
    }
    cout << "BST Inorder Traversal: ";
    tree.display();
    return 0;
}