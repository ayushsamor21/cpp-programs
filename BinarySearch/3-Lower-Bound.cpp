#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int key) {
    int low = 0, high = n -1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        if ( arr[mid] >= key ) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main () {
    int arr[] = {10, 20, 30, 40, 50, 60};
    int key = 33;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = lowerBound(arr, n, key);

    cout << "The lower bound of "<< key <<" is: " << result << endl;
    return 0;
}