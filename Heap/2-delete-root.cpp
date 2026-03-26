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

    void deleteRoot() {
        if (size == 0) return;

        arr[1] = arr[size];  
        size--;              

        int i = 1;

        while (2*i <= size) {
            int left = 2*i;
            int right = 2*i + 1;
            int largest = i;

            if (left <= size && arr[left] > arr[largest])
                largest = left;

            if (right <= size && arr[right] > arr[largest])
                largest = right;

            if (largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else break;
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

    cout << "Before delete: ";
    h.print();

    h.deleteRoot();

    cout << "After delete: ";
    h.print();

    return 0;
}