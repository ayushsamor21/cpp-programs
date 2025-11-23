#include <iostream>
using namespace std;

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

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Push element onto stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << value << endl;
            return;
        }
        data[++top] = value;
    }

    // Pop element from stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
            return -1; // sentinel value
        }
        return data[top--];
    }

    // Peek at top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return data[top];
    }

    // Display all elements
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

// Main function
int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack stack(size);

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
