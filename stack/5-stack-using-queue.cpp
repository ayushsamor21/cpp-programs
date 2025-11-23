#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q;

public:
    StackUsingQueue() {}

    void push(int value) {
        q.push(value);
        int n = q.size();
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int topValue = q.front();
        q.pop();
        return topValue;
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements (top → bottom): ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingQueue stack;

    cout << "Pushing elements 10, 20, 30 into the stack...\n";
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "\nTop element: " << stack.top() << endl;

    cout << "Popped element: " << stack.pop() << endl;
    stack.display();

    cout << "\nIs stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
