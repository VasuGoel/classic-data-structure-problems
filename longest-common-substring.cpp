#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
string longestCommonSubstring(string s, string t) {
    int m = s.size(), n = t.size(), len = INT_MIN, endIndex = -1;

    // dp[i][j] means longest common suffix in string s ending at index i and string t ending at index j
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // if last characters of substrings ending at i and j match dp[i][j] will be be 1 + dp[i-1][j-1] (to check if previous characters match too)
            if(s[i-1] == t[j-1])    dp[i][j] = 1 + dp[i-1][j-1];

            if(dp[i][j] > len) {
                len = dp[i][j];
                endIndex = j;
            }
        }
    }
    return (endIndex == -1) ? "" : t.substr(endIndex-len, len);
}

int main() {
    string s = "horse", t = "ceore";
    cout << longestCommonSubstring(s, t) << endl;

    return 0;
}

/*

    ""  c   e   o   r   e
""  0   0   0   0   0   0 
h   0   0   0   0   0   0 
o   0   0   0   1   0   0   --> substring "hor" and "ceor" have the longest common suffix i.e, "or"
r   0   0   0   0   2   0       which is the longest common substring in both strings
s   0   0   0   0   0   0 
e   0   0   1   0   0   1

*/
