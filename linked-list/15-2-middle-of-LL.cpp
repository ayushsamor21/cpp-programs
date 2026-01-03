#include <iostream>
using namespace std;

// optimal approach
// Fast and slow pointer : slow pointer moves on step and fast two steps 
// Compexity: O(N/2)

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

    void middleOfList(){
        if (head == nullptr) {
            cout << "Length is zero , Linked list is empty\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr || fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle of Linked List: " << slow->data << endl;
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
    list.middleOfList();
    return 0;
}
