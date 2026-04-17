#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int key) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int binarySearchRecursion(vector<int> &arr, int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
        return binarySearchRecursion(arr, mid + 1, high, key);
    else
        return binarySearchRecursion(arr, low, mid - 1, key);
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int key = 7;

    int result = binarySearch(arr, key);

    if (result != -1)
        cout << "Found at index " << result << "\n";
    else
        cout << "Not found\n";

    int resultRecusion = binarySearchRecursion(arr, 0, arr.size() - 1, key);

    if (resultRecusion != -1)
        cout << "Found at index " << resultRecusion;
    else
        cout << "Not found\n";

    return 0;
}