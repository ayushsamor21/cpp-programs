#include <iostream>
using namespace std;

// Brute-Force method: using count to know length and then half is the middle
// Compexity: O(N+N/2)

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

    int length() {
        if (head == nullptr) {
            cout << "Length is zero , Linked list is empty\n";
            return 0;
        }
        int lengthOfList = 0;
        Node* temp = head;
        while (temp != nullptr) {
            lengthOfList++;
            temp = temp->next;
        }
        return lengthOfList;
    }

    void middleOfList(int lengthOflist){
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if (count == lengthOflist/2) {
                cout << "The middle of list: " << temp->data << endl;
                return;
            }
            count++;
            temp = temp->next;
        }
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

    list.printList();
    cout << "\n";
    list.middleOfList(list.length());
    return 0;
}
