#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int> &v, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && v[l] > v[largest]) largest = l;
    if (r < n && v[r] > v[largest]) largest = r;

    if (largest != i) {
        swap(v[i], v[largest]);
        maxHeapify(v, n, largest);
    }
}

void buildMaxHeap(vector<int> &v) {
    int n = v.size();
    for (int i = n/2 - 1; i >= 0; i--)
        maxHeapify(v, n, i);
}

int main() {
    vector<int> v = {10, 20, 15, 30, 40};

    buildMaxHeap(v);

    for (int x : v) cout << x << " ";
}