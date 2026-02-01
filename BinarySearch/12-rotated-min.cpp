#include <iostream>
using namespace std;

int findMin(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // Minimum is in right half
        if (arr[mid] > arr[high]) {
            low = mid + 1;
        }
        // Minimum is in left half or mid
        else {
            high = mid;
        }
    }
    return arr[low];
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (rotated sorted array): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Minimum element: " << findMin(arr, n) << endl;
    return 0;
}
