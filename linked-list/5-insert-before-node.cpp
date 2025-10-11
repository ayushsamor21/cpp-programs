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

    void insertBeforeElement(int targetValue, int newValue){
        if (head == nullptr) {
            cout << "list is Empty!!";
            return;
        }

        Node* temp = head;
        while (temp != nullptr && temp->next->data != targetValue){
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Element not found !!";
            return;
        }
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
    int sizeOfList, element, targetValue, insertValue;
    cout << "Please enter the size of linked list: ";
    cin >> sizeOfList;

    for (int i = 0; i < sizeOfList; i++) {
        cout << "Please enter Element : ";
        cin >> element;
        list.append(element);
    }

    cout << "---Original Linked List---\n";
    list.print();

    cout << "Please enter target value: ";
    cin >> targetValue;

    cout << "Please enter the new value: ";
    cin >> insertValue;

    list.insertBeforeElement(targetValue, insertValue);

    cout << "---New Linked List---\n";
    list.print();
  
    return 0;
}