#include <iostream>
using namespace std;

class heap {
    int arr[100];
    int size = 0;

public:
    void insert(int val) {
        size++;
        arr[size] = val;

        int i = size;

        while (i > 1 && arr[i/2] < arr[i]) {
            swap(arr[i], arr[i/2]);
            i = i / 2;
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;   
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);

    h.print();

    return 0;
}