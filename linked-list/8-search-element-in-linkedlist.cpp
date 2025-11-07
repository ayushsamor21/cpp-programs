#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Destructor to free memory automatically
    ~LinkedList() {
        freeList();
    }

    // Append new node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Print linked list
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }

    // Search Element
    bool searchElement(int targetElement){
        Node* temp = head;
        while(temp != nullptr) {
            if (temp->data == targetElement){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Free all nodes
    void freeList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function
int main() {
    LinkedList list;
    int numOfElements, num, searchElement;

    cout << "Please enter the number of elements: ";
    cin >> numOfElements;

    for (int i = 0; i < numOfElements; i++) {
        cout << "Please enter the element: ";
        cin >> num;
        list.append(num);
    }

    cout << "Linked List: ";
    list.print();

    cout << "Please enter the element to search: ";
    cin >>searchElement;

    if (list.searchElement(searchElement)){
        cout << "The element "<< searchElement <<" is present in the linked list!!\n";
    } else {
        cout << "The element "<< searchElement <<" is not present in the linked list!!\n";
    }
    return 0;
}
