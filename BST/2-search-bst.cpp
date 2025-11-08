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

    bool search(Node* node, int key) {
        if (node == nullptr)
            return false; // base case: not found

        if (key == node->data)
            return true;   // when found

        if (key < node->data)
            return search(node->left, key);  // search in left subtree
        else
            return search(node->right, key); // search in right subtree
    }

    bool searchElement(int key) {
        return search(root, key);
    }

    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if (root == nullptr || root->val == val) 
    //         return root;

    //     if (val < root->val) 
    //         return searchBST(root->left, val);
    //     else 
    //         return searchBST(root->right, val);
    // }
};

int main() {
    int numberOfElements, element, key;
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

    cout << "Please enter the element to search: ";
    cin >> key;

    if (tree.searchElement(key)) {
        cout << "The element"<< key <<" is present!\n";
    } else {
        cout << "The element"<< key <<" is not present!\n";
    }
}