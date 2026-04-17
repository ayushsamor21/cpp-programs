#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

int randomPartition(vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    int temp = arr[randomIndex];
    arr[randomIndex] = arr[high];
    arr[high] = temp;

    return partition(arr, low, high);
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<int> arr;
    arr.push_back(10);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(1);
    arr.push_back(5);

    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}