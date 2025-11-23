#include <iostream>
#include <vector>
using namespace std;

// Complexity:  O(n^2)

void bubbleSort(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) { // j < n - i - 1 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    vector<int> arr(size);

    cout << "Enter " << size << " elements:\n";
    for (int i = 0; i < size; i++) {
        cout << "Enter element at index["<< i <<"]: ";
        cin >> arr[i];
    }

    bubbleSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
