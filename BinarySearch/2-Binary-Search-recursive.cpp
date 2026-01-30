#include <iostream>
using namespace std;

int binarySearch(int arr[], int small, int large, int key) {
    if (small > large) {
        return -1;
    }
    int mid = ( large + small ) / 2;
    if (arr[mid] == key) {
        return mid;
    } else if( arr[mid] < key) {
        return(binarySearch(arr, mid + 1, large, key));
    } else {
         return(binarySearch(arr, small, mid + 1, key));
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    int small = 0, large = n - 1;
    int result = binarySearch(arr,small, large, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}
