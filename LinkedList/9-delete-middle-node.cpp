#include <iostream>
using namespace std;

//Time complexity = O(N)
// Space complexity = O(1)

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
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
        return;
    }

    void deleteMiddleNode(int numOfElements) {
        if (head == nullptr || numOfElements == 1) {
            delete head;
            head = nullptr;
            return;
        }

        int middle = numOfElements / 2; // 0-based
        int index = 0;

        Node* curr = head;
        Node* prev = nullptr;

        while (index != middle) {
            prev = curr;
            curr = curr->next;
            index++;
        }

        prev->next = curr->next;
        delete curr;
    }


    void printLinkedList () {
        Node* temp = head;
        while ( temp != nullptr) {
            cout << temp->data;
            if ( temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void freeList () {
        Node* temp;
        while(head != nullptr) {
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
    list.printLinkedList();

    cout << "\nDeleted Middle element: ";
    list.deleteMiddleNode(numOfElements);
    list.printLinkedList();

    return 0;
}