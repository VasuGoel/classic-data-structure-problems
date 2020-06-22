#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
int editDistance(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0)  dp[i][j] = j;
            if(j == 0)  dp[i][j] = i;
            
            if(i != 0 && j != 0) {
                if(s[i-1] == t[j-1])    dp[i][j] = dp[i-1][j-1];
                else    dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s = "kitten", t = "sitting";
    cout << editDistance(s, t) << endl;

    return 0;
}

/*

dp[i][j] means we're considering substrings s upto index i and t upton index j, and we start comparing from last character.
If for dp[i][j], character in s[i-1] and t[j-1] are same then edit distance is same as dp[i-1][j-1]. Ex: s = "a", t = "a", their edit distance is same as s = "", t = "", i.e, 0
Otherwise, it's [ 1 + minimum (dp[i-1][j-1], dp[i-1][j], dp[i][j-1] ], where +1 is for current operation and min of these 3 dp cells is subproblem to find min between replacement, insertion and deletion. 

For strings s = "kitten", t = "sitting" :

    ""  s   i   t   t   i   n   g
""  0   1   2   3   4   5   6   7 
k   1   1   2   3   4   5   6   7 
i   2   2   1   2   3   4   5   6 
t   3   3   2   1   2   3   4   5 
t   4   4   3   2   1   2   3   4 
e   5   5   4   3   2   2   3   4 
n   6   6   5   4   3   3   2   3 

*/
