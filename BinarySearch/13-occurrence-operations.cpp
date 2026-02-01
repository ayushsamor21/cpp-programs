#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans;

    while (low <= high) {
        int mid = ( low + high) / 2;
        if (arr[mid] == target) {
            ans = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid - 1;
        } else {
            high = mid + 1;
        }
    }
    return ans;
}

int lastOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans;

    while (low <= high) {
        int mid = ( low + high) / 2;
        if (arr[mid] == target) {
            ans = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid - 1;
        } else {
            high = mid + 1;
        }
    }
    return ans;
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

    int target;
    cout << "Please enter the target element: ";
    cin >> target;

    int first = firstOccurrence(arr, n, target);
    int last = lastOccurrence(arr, n, target);

    cout << "First Occurrence: " << first << endl;
    cout << "Last Occurrence: " << last << endl;

    if (first == -1)
        cout << "Total Occurrences: 0";
    else
        cout << "Total Occurrences: " << (last - first + 1);

    return 0;
}