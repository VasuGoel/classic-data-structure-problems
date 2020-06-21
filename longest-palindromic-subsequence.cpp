#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(string s) {
    int n = s.size();
    // dp[i][j] means longest palindromic subsequence in string starting at index i and ending at j
    vector<vector<int>> dp(n, vector<int>(n));

    // lps of substrings of length 1 is 1 
    for(int i = 0; i < n; i++)  dp[i][i] = 1;

    // traversing diagonally from left to right
    for(int l = 1; l < n; l++) {
        for(int i = 0; i < n; i++) {
            int j = i+l;
            if(j < n) {
                if(s[i] == s[j])    dp[i][j] = 2 + dp[i+1][j-1];
                else    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    string s = "agbdba";
    cout << longestPalindromicSubsequence(s) << endl;

    return 0;
}

/*

For lps(i, j) if character at i and j are same then, dp[i][j] = 2 + dp[i+1][j-1]. Ex: for "aba" lps(0, 2) = 2 + lps(1, 1) -> 2 + 1 = 3
Otherwise, if they're not same, dp[i][j] = max(dp[i+1][j], dp[i][j-1]). Ex: for "abac" lps(0, 3) = max(lps(1,3), lps(0,2)) -> max(max(lps(2,3), lps(1,2)) , 2+lps(1,1)) -> max(1 , 2+1) -> 3

   a g b d b a
a  1 1 1 1 3 5 
g  0 1 1 1 3 3  -->  dp[0][5] means lps of substring starting at 0 and ending at index 5 
b  0 0 1 1 3 3       i.e, lps of the required string "agbdba" that is 5 ("abdba").
d  0 0 0 1 1 1       
b  0 0 0 0 1 1       
a  0 0 0 0 0 1 

*/
