#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
int shortestCommonSupersequence(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int j = 1; j <= n; j++)     dp[0][j] = 1 + dp[0][j-1];
    for(int i = 1; i <= m; i++)     dp[i][0] = 1 + dp[i-1][0];

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == t[j-1])    dp[i][j] = 1 + dp[i-1][j-1];
            else    dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) cout << dp[i][j] << "  ";
        cout << endl;
    }
    return dp[m][n];
}

int main() {
    string s = "abcd", t = "bde";
    cout << shortestCommonSupersequence(s, t) << endl;

    return 0;
}

/*

Shortest Common Supersequence, (or SCS) of strings s and t, is the shortest super-sequence such that s and t are subsequences of it.
Ex: s = "abcd", t = "bde" and their SCS is "abcde" with lenght 5.

SCS(s[0...i], t[0...j]) = SCS(s[0...i-1], t[0...j-1]) + s[i], iff s[i] == s[j] (last characters match). Ex: SCS("ab", "cb") = SCS("a", "c") + "b"
But if last characters don't match then, SCS(s[0...i], t[0...j]) = min(SCS(s[0...i-1], t[0...j-1])) + (s[i] or t[j] resp.). Ex: s = "abc", t = "bcd", SCS(s, t) = min(SCS("ab", "bcd"), SCS("abc", "bc")) + ("c" or "d" resp.)

    "" b  d  e
""  0  1  2  3  
a   1  2  3  4  
b   2  2  3  4  
c   3  3  4  5  
d   4  4  4  5

*/
