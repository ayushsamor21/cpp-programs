#include <iostream>
using namespace std;

class Stack {
private:
    int *data;      // array to store stack elements
    int capacity;   // maximum size of stack
    int top;        // index of top element

public:
    // constructor
    Stack(int cap) {
        capacity = cap;
        data = new int[capacity];
        top = -1;
    }

    // destructor
    ~Stack() {
        delete[] data;
    }

    // check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // add element to stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << endl;
            return;
        }
        data[++top] = value;
    }

    // remove element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return -1;
        }
        return data[top--];
    }

    // see top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }

    // show all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// main function
int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);   // create stack

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        int value;
        cout << "Please enter the element: ";
        cin >> value;
        stack.push(value);
    }

    cout << "Current stack:\n";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    cout << "Popping one element\n";
    int removed = stack.pop();
    if (removed != -1)
        cout << "Popped: " << removed << endl;

    cout << "Stack after pop:\n";
    stack.display();

    return 0;
}
