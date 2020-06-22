#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
int rodCutting(vector<int> lens, vector<int> prices, int l) {
    int m = lens.size();
    vector<vector<int>> dp(m+1, vector<int>(l+1));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= l; j++) {
            if(j < lens[i-1])   dp[i][j] = dp[i-1][j];
            else    dp[i][j] = max(dp[i-1][j], prices[lens[i-1]-1] + dp[i][j-lens[i-1]]);
        }
    }
    return dp[m][l];
}

int main() {
    vector<int> lens {1, 2, 3, 4}, prices {2, 5, 7, 8};
    int l = 4;
    cout << rodCutting(lens, prices, l) << endl;

    return 0;
}

/*
    0 1 2 3 4
0   0 0 0 0 0 
1   0 2 4 6 8 
2   0 2 5 7 10 
3   0 2 5 7 10 
4   0 2 5 7 10

*/
