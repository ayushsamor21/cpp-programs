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

//  Stack class
class Stack {
public:
    Node* top;
    int size;

    // Constructor
    Stack(){
        top = nullptr;
        size = 0;
    }

    // Add new element
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Remove element 
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!!";
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next ;
        delete temp;
        size--;
        return poppedValue;
    }

    // If stack empty
    bool isEmpty() {
        return size == 0;
    }

    // display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack underflow!!" << endl;
            return;
        }
        Node* temp = top;  // use a temp pointer to traverse
        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next; // move to next node
        }
        cout << "NULL" << endl;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }
};

int main() {
    int numberOfElement, nodeValue;
    cout << "Please enter the number of element: ";
    cin >> numberOfElement;

    Stack stack;

    for(int i = 0; i < numberOfElement; i++) {
        cout << "Enter element: ";
        cin >> nodeValue;
        stack.push(nodeValue);
    }
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;
}