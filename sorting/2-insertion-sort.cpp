#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n) {
    int num, j;
    for (int i = 1; i < n; i++) {
        num = arr[i];
        j = i - 1;
        while ( j >= 0 && arr[j] > num) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = num;
    }
}

// Print Array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 10, 6, 4, 12, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}