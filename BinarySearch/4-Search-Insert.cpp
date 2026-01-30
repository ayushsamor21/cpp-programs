#include <iostream>
using namespace std;

int searchInsert (int arr[], int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main () {
    int arr[] = {1, 3, 5, 7, 9, 10};
    int value = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = searchInsert(arr, value, n);
    cout << "The value "<<value<<" should be inserted: " << result << endl;
    return 0;
}