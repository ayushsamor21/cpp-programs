#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    int* data;      // dynamic array to store elements
    int top;        // index of the top element
    int capacity;   // maximum stack size

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        data = new int[capacity];
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] data;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << endl;
            return;
        }
        data[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return -1; 
        }
        return data[top--];
    }
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << data[i] << "->";
        }
        cout << endl;
    }

};

class LinkedList {
private:
    Node* head;
public:
    LinkedList () {
        head = nullptr;
    }

    void stackReverse(int numOfElements) {
        Stack stack(numOfElements);
        Node* temp = head;
        while (temp != nullptr) {
            stack.push(temp->data);
            temp = temp->next;
        }
        stack.display();
    }

    void append (int value) {
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
        return;
    }

    void printLinkedList () {
        Node* temp = head;
        while ( temp != nullptr) {
            cout << temp->data;
            if ( temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
    }

    void freeList () {
        Node* temp;
        while(head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~LinkedList() {
        freeList();
    }
};

int main() {
    LinkedList list;
    int numOfElements, num;

    cout << "Please enter the number of elements: ";
    cin >> numOfElements;


    for (int i = 0; i < numOfElements; i++) {
        cout << "Please enter the element: ";
        cin >> num;
        list.append(num);
    }

    cout << "Linked List: ";
    list.printLinkedList();
    cout << "\n";

    cout << "Reverse List: ";
    list.stackReverse(numOfElements);

    return 0;
}