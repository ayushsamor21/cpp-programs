#include <iostream>
using namespace std;

int firstOccur(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            first = mid;
            high = mid - 1;   
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccur(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            last = mid;
            low = mid + 1;  
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return last;
}

int countOccurrence(int arr[], int n, int key) {
    int first = firstOccur(arr, n, key);
    if (first == -1) return 0;   
    int last = lastOccur(arr, n, key);
    return last - first + 1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 8, 8, 11, 15};
    int key = 8;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Count of " << key << " is: "
         << countOccurrence(arr, n, key) << endl;

    return 0;
}
