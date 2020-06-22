#include <bits/stdc++.h>
using namespace std;

// DP. O(n^3) time, O(n^2) space
bool wordBreak(string s, unordered_set<string> dict) {
    int n = s.size();

    // dp[i][j] = 1, means substring starting at i and ending at j is either be present in dictionary or can be broken into words that are all in dictionary
    vector<vector<bool>> dp(n, vector<bool>(n));

    // check if all substrings of length 1 are present in dict
    for(int i = 0; i < n; i++)  dp[i][i] = (dict.count(s.substr(i, 1))) ? 1 : 0;

    // traverse diagonally from left to right (considering substrings of all length, 1 ≤ len ≤ n-1)
    for(int l = 1; l < n; l++) {
        for(int i = 0; i < n; i++) {
            int j = i+l;
            if(j < n) {
                // check if substring from i to j is present in dict
                if(dict.count(s.substr(i, j-i+1)))  dp[i][j] = 1;
                // if not keep splitting substring from (i, k) and (k+1, j), at i ≤ k < j and check if for any split at k, dp[i][k] && dp[k+1][j] are true (i.e, substrings from (i, k) and (k+1, j) are either present in dict or can be broken into words that are in dict, which are subproblems of course)
                else {
                    for(int k = i; k < j; k++) {
                        if(dp[i][k] && dp[k+1][j]) {
                            dp[i][j] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    string s = "iamlit";
    unordered_set<string> dict {"a", "am", "lit", "i"};

    if(wordBreak(s, dict))  cout << "\"" << s << "\" can be broken into words that are in dictionary\n";
    else    cout << "\"" << s << "\" cannot be broken into words that are in dictionary\n";

    return 0;
}

/*

Global answer is dp[0][5], means we're considering substring from index 0 to index 5 (entire string)

    0 1 2 3 4 5
0   1 1 1 0 0 1 
1   0 1 1 0 0 1 
2   0 0 0 0 0 0 
3   0 0 0 0 0 1 
4   0 0 0 0 1 0 
5   0 0 0 0 0 0

*/
