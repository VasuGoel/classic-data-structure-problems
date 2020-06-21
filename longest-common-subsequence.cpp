#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
int longestCommonSubsequence(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
            else    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

int main() {
    string s = "horse", t = "corpse";
    cout << longestCommonSubsequence(s, t) << endl;

    return 0;
}
