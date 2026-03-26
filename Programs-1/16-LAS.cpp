#include <iostream>
#include <vector>
using namespace std;

int LIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // Each element is LIS of length 1 initially

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS: " << LIS(arr);
}