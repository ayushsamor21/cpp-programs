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

    Node* findMaxNode(Node* node) {
        if (node == nullptr) // tree is empty
            return nullptr; 

        if (node->right == nullptr) // found node
            return node;

        return findMaxNode(node->right); // move to right subtree
    }

    Node* findMax() {
        return findMaxNode(root);
    }

    int findMinValue(Node* node) {
        if (node == nullptr) {
            cout << "Tree is empty!" << endl;
            return -1; 
        }

        if (node->left == nullptr)
            return node->data; 

        return findMinValue(node->left);
    }

    int findMin() {
        return findMinValue(root);
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
    cout << endl;

    Node* maxNode = tree.findMax();
    if (maxNode != nullptr)
        cout << "Maximum element in BST: " << maxNode->data << endl;
    else
        cout << "The tree is empty!" << endl;

    cout << "The Minimmum element in BST: " << tree.findMin() << endl;
}

