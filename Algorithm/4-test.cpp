#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(arr[random], arr[high]);
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}