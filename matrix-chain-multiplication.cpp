#include <bits/stdc++.h>
using namespace std;

// DP. O(n^3) time, O(n^2) space
int minMultiplicationOperations(vector<int> row, vector<int> col) {
    int n = row.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    // cost(i, i) = 0
    for(int i = 0; i < n; i++)  dp[i][i] = 0;

    // we traverse diagonally since at any point we need cells on left and below
    for(int l = 1; l < n; l++) {
        for(int i = 0; i < n; i++) {
            int j = i + l;
            if(j < n) {
                for(int k = i; k < j; k++) {
                    int subprob = dp[i][k] + dp[k+1][j] + (row[i] * col[k] * col[j]);
                    dp[i][j] = min(dp[i][j], subprob);
                }
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    // 3 matrices M0, M1, M2 with dimensions 1x2, 2x3, 3x4
    vector<int> row {1, 2, 3}, col {2, 3, 4};
    cout << minMultiplicationOperations(row, col) << endl;

    return 0;
}

/*

dp[i][j] denotes min multiplication operations needed to multiply matrices from Mi to Mj. Global answer is dp[0][2] but we need to solve the subproblems in order to get there.

Note: cost(i, j) and dp[i][j] are synonymous here.
We know, cost(i, i) = 0, because we cannot multiply a single matrix by anything hence cost(0, 0), cost(1, 1), cost(2, 2) are all 0.
Also, for matrices (Mi, ..., ..., Mj), cost(i, j) = cost(i, k) + cost(k+1, j) + (rowi * colk * colj), and we need to minimize cost over all i ≤ k < j

Ex: Consider matrices M0 (1x2) and M1 (2x3), total multiplication operations are cost(0, 1) = cost(0, 0) + cost(1, 1) + (1 x 2 x 3) = 0 + 0 + 6 = 6. 
Since, matrix multiplication is O(mnp) for matrices with dimensions mxn and nxp.

For, 3 matrices M0, M1, M2 with dimensions 1x2, 2x3, 3x4, DP table is as follows:

    0   1   2
0   0   6   18
1   ∞   0   24
2   ∞   ∞   0

*/
