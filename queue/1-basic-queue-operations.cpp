#include <iostream>
using namespace std;

class Queue {
private:
    int *data; // array pointer
    int front; // index of front element
    int rear; // index of rear element
    int capacity; // maximum capacity of queue

public:
    // constructor
    Queue(int size) {
        capacity = size;
        data = new int[capacity];
        front = -1;
        rear = -1;
    }

    // destructor
    ~Queue() {
        delete[] data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    // check if queue is full 
    bool isFull() {
        return (rear == capacity - 1);
    }

    // Add element
    void enqueue(int value) {
        if (isFull()){
            cout << "Queue is full! Cannot insert " << value << endl;
            return;
        }
        if (front == -1){
            front = 0;
        } 
        data[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; 
        }
        int removedValue = data[front++];
        return removedValue;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return data[front];
    }
    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue queue(size);

    for (int i = 0; i < size; i++) {
        int value;
        cout << "Please enter the element in queue: ";
        cin >> value;
        queue.enqueue(value);
    }

    cout << "Current queue:\n";
    queue.display();

    cout << "Front element: " << queue.getFront() << endl;

    cout << "the dequeued element: " << queue.dequeue() << endl;

    cout << "Queue after dequeue:\n";
    queue.display();

    return 0;
}




