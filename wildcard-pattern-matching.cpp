#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
bool wildcardPatternMatch(string s, string p) {
    int m = s.size(), n = p.size(), j = 0;
    vector<vector<bool>> dp(m+1, vector<bool>(n+1));

    dp[0][0] = 1;   // match("", "") = 1
    // if p = "**ab*c", then dp[0][1] = 1, dp[0][2] = 1
    while(p[j++] == '*')    dp[0][j] = 1;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == p[j-1] || p[j-1] == '?')   dp[i][j] = dp[i-1][j-1];
            else if(p[j-1] == '*')  dp[i][j] = dp[i-1][j] | dp[i][j-1];
            else    dp[i][j] = 0;
        }
    }
    return dp[m][n];
}

int main() {
    string s = "xaypqz", p = "x?y*z";

    if(wildcardPatternMatch(s, p))     cout << "Match\n";
    else    cout << "Not a match\n";
    return 0;
}

/*

? = single character
* = zero or more characters

Consider string s = "xaypqz" and pattern p = "x?y*z", which is a match. There are 3 cases when wildcard pattern matching:

1. match(s[0...i], p[0...j]) = match(s[0...i-1], p[0...j-1]), if s[i] == p[j] (last characters match) or p[j] == '?'. Ex: match("ab", "a?") = match("a", "a") = match("", "") = true
2. But if pattern's last character is "*" then, match(s[0...i], p[0...j]) = match(s[0...i-1], p[0...j]) | match(s[0...i], p[0...j-1]) (means if any of them is true),
   Ex: match("abc", "a*") = match("ab",  "a*") | match("abc", "a") = match("a", "a*") | match("ab", "a") = match("", "a*") | match("a", "a") = true
                             (breaks further)       (is false)       (breaks further)      (is false)         (is false)        (is true)
3. Otherwise, dp[i][j] = 0

DP table for above string s, and pattern p:

    "" x  ?  y  *  z
""  1  0  0  0  0  0  
x   0  1  0  0  0  0  
a   0  0  1  0  0  0  
y   0  0  0  1  1  0
p   0  0  0  0  1  0  
q   0  0  0  0  1  0  
z   0  0  0  0  1  1

*/
