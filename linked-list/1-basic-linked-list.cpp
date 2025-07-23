#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};
// class Node {
// public:
//     int data;
//     Node* next;

//     Node(int value) : data(value), next(nullptr) {}
// };

Node* append(Node* head, int value){
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return head;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if ( temp->next != nullptr) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << endl;;
}

void freeList(Node* head) {
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp; 
    }
}

int main() {
    int numOfElements, num;

    cout << "Please enter the number of elements: ";
    cin >> numOfElements;

    Node* head = nullptr;
    for (int i = 0; i < numOfElements; i++) {
        cout << "Please enter the element: ";
        cin >> num;
        head = append(head, num);
    }

    printLinkedList(head);
    freeList(head);
    return 0;
}
