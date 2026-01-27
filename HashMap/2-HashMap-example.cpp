#include <iostream>
#include <unordered_map>
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

int main() {

    // hash map: Node address -> bool
    unordered_map<Node*, bool> mp;

    // create nodes
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);

    // -------- INSERT --------
    mp[n1] = true;
    mp[n2] = false;

    // -------- ACCESS --------
    if (mp.find(n1) != mp.end()) {
        cout << "n1 found, value = " << mp[n1] << endl;
    }

    if (mp.find(n2) != mp.end()) {
        cout << "n2 found, value = " << mp[n2] << endl;
    }

    // -------- DELETE --------
    mp.erase(n1);

    if (mp.find(n1) == mp.end()) {
        cout << "n1 deleted from hash map" << endl;
    }

    return 0;
}
