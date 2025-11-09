#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> stack;  // create an empty deque

    stack.push_back(10);  // [10]
    stack.push_back(20);  // [10, 20]
    stack.push_back(30);  // [10, 20, 30]

    stack.push_front(40); // [40, 10, 20, 30]
    stack.push_front(50); // [50, 40, 10, 20, 30]

    cout << stack.back() << " popped from deque" << endl;
    stack.pop_back();
    cout << "Top element is: " << stack.back() << endl;
    return 0;
}

/*
 <deque> — Important Functions Cheat Sheet

Basic Operations
----------------------------------------
push_back(x)     → Add element to the back            → dq.push_back(10);
push_front(x)    → Add element to the front           → dq.push_front(5);
pop_back()       → Remove element from the back       → dq.pop_back();
pop_front()      → Remove element from the front      → dq.pop_front();

Accessing Elements
----------------------------------------
front()          → Access first element               → dq.front();
back()           → Access last element                → dq.back();
at(index)        → Access element at given index      → dq.at(1);
operator[]       → Access element directly            → dq[1];

 Notes:
- Deque = "Double Ended Queue" → insertion/deletion possible from both ends.
- Unlike vector, it grows efficiently from both front and back.
- Commonly used to implement stacks, queues, and sliding window problems.
*/
