#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
string longestPalindromicSubstring(string s) {
    int n = s.size(), len = 1, startIndex = 0;
    vector<vector<int>> dp(n, vector<int>(n));

    // longest palindromic substring in substrings of len 1 is 1
    for(int i = 0; i < n; i++)  dp[i][i] = 1;

    // traversing daigonally and considering all substrings
    for(int l = 1; l < n; l++) {
        for(int i = 0; i < n; i++) {
            int j = i + l;
            if(j < n) {
                // in substring from i to j, if characters at index i and j match check if dp[i+1][j-1] is also non-zero (means substring from i+1 to j-1 is also valid, say, i=0, j=3 in "ansa") or if, j-1 = 1 (substring is of len 2, say, i=2, j=3 in "cbbd")
                if(s[i] == s[j] && (j-i == 1 || dp[i+1][j-1] != 0))    dp[i][j] = 2 + dp[i+1][j-1];
                
                if(dp[i][j] > len) {
                    len = dp[i][j];
                    startIndex = i;
                }
            }
        }
    }
    return s.substr(startIndex, len);
}

int main() {
    string s = "bananas";
    cout << longestPalindromicSubstring(s) << endl;

    return 0;
}

/*

    b a n a n a s
b   1 0 0 0 0 0 0 
a   0 1 0 3 0 5 0 
n   0 0 1 0 3 0 0 
a   0 0 0 1 0 3 0 
n   0 0 0 0 1 0 0 
a   0 0 0 0 0 1 0 
s   0 0 0 0 0 0 1 

*/
