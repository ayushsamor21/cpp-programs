#include <iostream>
using namespace std;

int searchValue(int arr[], int key, int n) {
     int low = 0, high = n - 1;
    int result = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int key = 33;
    int n = sizeof(arr) / sizeof(arr[0]);

    int isExist = searchValue(arr, key, n);
    if (isExist != -1) {
        cout << "The value does exist!";
    } else {
        cout << "The value does not exist!";
    }
    return 0;
}
