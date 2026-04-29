#include <iostream>
#include <vector>
using namespace std;

int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Base cases
    for (int i = 0; i <= m; i++)
        dp[i][0] = i; // delete all characters

    for (int j = 0; j <= n; j++)
        dp[0][j] = j; // insert all characters

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // no operation
            } else {
                dp[i][j] = 1 + min({
                    dp[i - 1][j],     // delete
                    dp[i][j - 1],     // insert
                    dp[i - 1][j - 1]  // replace
                });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "kitten";
    string s2 = "sitting";

    cout << "Edit Distance: " << editDistance(s1, s2) << endl;

    return 0;
}