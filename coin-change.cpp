#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
int coinChange(vector<int> coins, int n) {
    int m = coins.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    dp[0][0] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(j < coins[i-1])    dp[i][j] = dp[i-1][j];
            else    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
        }
    }
    return dp[m][n];
}

int main() {
    vector<int> coins {1,3,5,7};
    int n = 8;
    cout << coinChange(coins, n) << endl;

    return 0;
}
