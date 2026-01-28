#include <iostream>
using namespace std;

void linearSearch(int arr[], int key, int n) {
    for (int i = 0; i < n; i++) {
        if (key == arr[i]) {
            cout << "The element is present in array at index["<<i<<"]: " << key << endl;
            return;
        }
    }
    cout << "The element is not present in array.";
}

// Print Arrayx
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i ++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    cout << "Please enter the element to search: ";
    cin >> key;

    linearSearch(arr, key, n);
    return 0;
}
