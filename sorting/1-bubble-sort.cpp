#include <iostream>
using namespace std;

void bubbleSort(int arr[], int sizeOfArray) {
    for (int i = 0; i < sizeOfArray - 1; i++) {
        for (int j = 0; j < sizeOfArray - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int sizeOfArray;
    cout << "Please enter the size of Array: ";
    cin >> sizeOfArray;

    int arr[sizeOfArray];

    for(int i = 0; i < sizeOfArray; i++) {
        cout << "Please enter element at ["<< i <<"] : "; 
        cin >> arr[i];
    }

    bubbleSort(arr, sizeOfArray);
    
    cout << "---Sorted Array---";
    for (int i = 0; i < sizeOfArray; i++){
        cout << arr[i] << " ";
    }

    return 0;
}