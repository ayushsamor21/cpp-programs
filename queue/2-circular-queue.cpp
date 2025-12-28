#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *data;      // array pointer
    int front;      // index of front element
    int rear;       // index of rear element
    int capacity;   // size of the queue

public:
    
    CircularQueue(int size) {
        capacity = size;
        data = new int[capacity];
        front = -1;
        rear = -1;
    }

    // Destructor
    ~CircularQueue() {
        delete[] data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % capacity == front);
    }

    // Insert element in circular queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot insert " << value << endl;
            return;
        }

        if (front == -1) { 
            front = 0; 
        }

        rear = (rear + 1) % capacity;
        data[rear] = value;
    }

    // Remove element
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int removedValue = data[front];

        // If only one element is left
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        return removedValue;
    }

    // Get front element
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
        int i = front;

        while (true) {
            cout << data[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter size of circular queue: ";
    cin >> size;

    CircularQueue q(size);

    for (int i = 0; i < size; i++) {
        int value;
        cout << "Enter element: ";
        cin >> value;
        q.enqueue(value);
    }

    cout << "Current queue:\n";
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    cout << "Dequeued element: " << q.dequeue() << endl;

    cout << "Queue after dequeue:\n";
    q.display();

    return 0;
}
