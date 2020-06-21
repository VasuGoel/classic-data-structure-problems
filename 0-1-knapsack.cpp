#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
int knapsack(vector<int> values, vector<int> weights, int w) {
    int m = values.size();
    vector<vector<int>> dp(m+1, vector<int>(w+1));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= w; j++) {
            if(j < weights[i-1])    dp[i][j] = dp[i-1][j];
            else    dp[i][j] = max(dp[i-1][j], values[i-1] + dp[i-1][j-weights[i-1]]);
        }
    }
    return dp[m][w];
}

int main() {
    vector<int> values {60, 50, 70, 30}, weights {5, 3, 4, 2};
    int w = 5;
    cout << knapsack(values, weights, w) << endl;

    return 0;
}
