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

    // ---- Height function added ----
    int height(Node* node) {
        if (node == nullptr)
            return -1;       // height in terms of edges (common definition)
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int getHeight() {
        return height(root);
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

    cout << "\nHeight of BST: " << tree.getHeight();

    return 0;
}
