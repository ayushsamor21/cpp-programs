#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node (int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList () {
        head = nullptr;
    }

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
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
        temp = temp->next;
        }
    }
     void freeList() {
        Node* temp;
        while (head != nullptr) {
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
    list.printList();

    return 0;
}
        
