#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
string longestRepeatedSubsequence(string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1));

    // same as longest common subsequence with string itself and added condition that index of matching characters should be different
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == s[j-1] && i != j)  dp[i][j] = 1 + dp[i-1][j-1];
            else    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // retrieving sequence from dp table (starting from bottom right)
    string seq;
    int i = n, j = n;
    while(i > 0 && j > 0) {
        if(dp[i][j] == dp[i-1][j-1] + 1) {
            seq.insert(seq.begin(), s[i-1]);
            i--, j--;
        }
        else if(dp[i][j] == dp[i-1][j]) i--;
        else    j--;
    }
    return seq;
}

int main() {
    string s = "aabcbdda";
    cout << longestRepeatedSubsequence(s) << endl;

    return 0;
}

/*

Longest Repeated Subsequence problem is same as longest common subsequence with the string itself and added constraint that matching character must not be at same indices.
So, LRS(str) = LCS(str, str), where matching characters must not be at same indices

    "" a  a  b  c  b  d  d  a
""  0  0  0  0  0  0  0  0  0  
a   0  0  1  1  1  1  1  1  1  
a   0  1  1  1  1  1  1  1  2  
b   0  1  1  1  1  2  2  2  2  
c   0  1  1  1  1  2  2  2  2  
b   0  1  1  2  2  2  2  2  2  
d   0  1  1  2  2  2  2  3  3  
d   0  1  1  2  2  2  3  3  3  
a   0  1  2  2  2  2  3  3  3

To retrieve the sequence from dp table start from bottom right and if current cell is 1 greater than diagonal cell in above row (dp[i][j] == dp[i-1][j-1] + 1) add character at that index to sequence
and move to that cell, otherwise move direction where maximum is i.e, cell above or cell on left

*/
