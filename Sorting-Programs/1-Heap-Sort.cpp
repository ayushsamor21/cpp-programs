#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &vec, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[left] > vec[largest])
        largest = left;
    if (right < n && vec[right] > vec[largest])
        largest = right;

    if (largest != i) {
        swap(vec[i], vec[largest]);
        heapify(vec, n, largest);
    }
}

void heapSort(vector<int> &vec) {
    int n = vec.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vec, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(vec[0], vec[i]);
        heapify(vec, i, 0);
    }
}

int main() {
    vector<int> vec = {12, 11, 13, 5, 6, 7};

    heapSort(vec);

    for (int val : vec)
        cout << val << " ";
    cout << endl;

    return 0;
}