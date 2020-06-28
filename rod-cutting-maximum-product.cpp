#include <bits/stdc++.h>
using namespace std;

// O(n^2) time, O(n) space
int maxProductRodCutting(int n) {
    vector<int> dp(n+1);
    iota(dp.begin(), dp.end(), 0);      // max product at number i would be at least i

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            dp[i] = max(dp[i], j*dp[i-j]);
        }
    }
    return dp[n];
}

int main() {
    int n = 10;
    cout << maxProductRodCutting(n) << endl;

    return 0;
}

/*

We have to find the max product of prices, if a rod of length 'n' is cut in smaller pieces, where piece of length 'i' has price 'i'.
Ex: rod of length 4 can be cut so as to yeild various profits but the max is 4.
1*1*1*1 = 1
1*1*2 = 2
1*3 = 3
2*2 = 4     -> max product

If we cut a rod of length 'i' into two pieces, 'j' and 'i-j', we can optimally find the max product as, dp[i] = max(dp[i], j*dp[i-j]), where 1 ≤ j < i
For instance, dp[6] = maximum of (1*dp[5], 2*dp[4], 3*dp[3], 4*dp[2], 5*dp[1]) = max(6, 8, 9, 8, 5) = 9.

nums:   0   1   2   3   4   5   6   7   8   9   10
dp:     0   1   2   3   4   6   9   12  18  27  36

*/
