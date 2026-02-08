#include <iostream>
using namespace std;

int countLessOrEqual(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= target) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans + 1;
}

int countGreaterOrEqual(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return n - ans;
}
   

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << countLessOrEqual(arr, n, key);
    cout << countGreaterOrEqual(arr, n, key);
    return 0;
}