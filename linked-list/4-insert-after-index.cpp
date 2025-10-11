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

class LinkedList{
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        freeList();
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

    void insertAfterElement(int targetValue, int newValue) {
        Node* temp = head;

        // Find the target node
        while (temp != nullptr && temp->data != targetValue) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node not found!!";  // Target not found 
            return;
        }

        // Insert after target
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfterIndex(int targetIndex, int newValue) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        int count = 0;

        // Traverse to the target index
        while (temp != nullptr && count < targetIndex) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) {
            cout << "Index out of bounds!" << endl;
            return;
        }

        // Insert new node after temp
        Node* newNode = new Node(newValue);
        newNode->next = temp->next;
        temp->next = newNode;
    }


    void freeList() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int sizeOfList, element, targetIndex, insertValue;
    cout << "Please enter the size of linked list: ";
    cin >> sizeOfList;

    for (int i = 0; i < sizeOfList; i++) {
        cout << "Please enter Element : ";
        cin >> element;
        list.append(element);
    }

    cout << "---Original Linked List---\n";
    list.print();

    cout << "Please enter the index to insert after: ";
    cin >> targetIndex;

    cout << "Please enter the  new node value: ";
    cin >> insertValue;

    list.insertAfterIndex(targetIndex, insertValue);
    cout << "---New Linked List---\n";
    list.print();

    return 0;
}