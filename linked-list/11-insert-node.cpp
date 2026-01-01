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
    LinkedList() {
        head = nullptr;
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
    }

    void printList() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
    }

    void insertInBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertBeforeNode(int newValue) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        int targetNode;
        cout << "Please enter the Node to insert before: ";
        cin >> targetNode;

        if (head->data == targetNode) {
            Node* newNode = new Node(newValue);
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {  
            if (temp->next->data == targetNode) {
                Node* newNode = new Node(newValue); 
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }

        cout << "Target node not found\n";
    }



    void insertAfterNode(int newValue) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        int targetNode;
        cout << "Please enter the Node to insert after: ";
        cin >> targetNode;

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == targetNode) {
                Node* newNode = new Node(newValue); 
                newNode->next = temp->next;
                temp->next = newNode;
                return; 
            }
            temp = temp->next;
        }

        cout << "Target node not found\n";
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
    int numberOfElement, element;
    cout << "Please enter the number of elements: ";
    cin >> numberOfElement;

    LinkedList list;

    for (int i = 0; i < numberOfElement; i++) {
        cout << "Please enter the element: ";
        cin >> element;
        list.append(element);
    }

    cout << "Initial list: ";
    list.printList();
    cout << endl;

    int newValue;
    cout << "Please enter the new value to insert at the beginning: ";
    cin >> newValue;
    list.insertInBeginning(newValue);
    list.printList();
    cout << endl;

    cout << "Please enter the new value to insert after: ";
    cin >> newValue;
    list.insertAfterNode(newValue);
    list.printList();
    cout << endl;

    cout << "Please enter the new value to insert before: ";
    cin >> newValue;
    list.insertBeforeNode(newValue);
    list.printList();
    cout << endl;

    cout << "Final list: ";
    list.printList();
    cout << endl;

    return 0;
}

