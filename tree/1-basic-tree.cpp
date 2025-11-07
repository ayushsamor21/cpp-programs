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

class Tree {
public: 
    Node* root;

    Tree() {
        root = nullptr;
    }

    void printInorder(Node* node) {
        if (node == nullptr)
            return;

        printInorder(node->left);       // Visit left subtree
        cout << node->data << " ";      // Visit current node
        printInorder(node->right);      // Visit right subtree
    }

    void printInorder() {
        printInorder(root);  ;  // Calls the above function starting from the root
    }
};

int main() {
    Tree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    //         1
    //       /   \
    //      2     3
    //     / \
    //    4   5

    cout << "Inorder Traversal: ";
    tree.printInorder();  // prints: 4 2 5 1 3
}
