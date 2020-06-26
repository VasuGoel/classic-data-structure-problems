#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n^2) space
pair<int, int> potOfGold(vector<int> coins) {
    int n = coins.size();
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));

    for(int i = 0; i < n; i++)  dp[i][i] = {coins[i], 0};

    // traversing diagonally considering subarrays of all lengths
    for(int l = 1; l < n; l++) {
        for(int i = 0, j; i < n; i++) {
            j = i+l;
            if(j < n) {
                dp[i][j].first = max(coins[i] + dp[i+1][j].second, coins[j] + dp[i][j-1].second);
                dp[i][j].second = min(dp[i+1][j].first, dp[i][j-1].first);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    vector<int> coins {4, 6, 2, 3};
    pair<int, int> profit = potOfGold(coins);
    
    cout << profit.first << " " << profit.second << endl;
    return 0;
}

/*

The problem is to maximize player A's coins, assuming player B plays optimally and A starts the game. At each turn a player can choose coins only from the ends of the vector coins.
Consider coins: [4, 6, 2, 3], the max player A and B can get are 9 and 6 coins resp.

Coins left      Turn        Coins chosen

4 6 2 3          A              3
4 6 2            B              4       --> Player A's total = 3 + 6 = 9
6 2              A              6       --> Player B's total = 4 + 2 = 6
2                B              2

We can solve this using DP and storing pairs containing player 1's and 2's profits at each cell. So, dp[i][j] = pair(a, b), means total profit 'a' player 1 can make, and 'b' player 2 can make if we're considering only coins from index i to j.
Naturally, when i == j, means we're only considering 1 index and all those coins at that index will be chosen by player 1 and player 2 will get 0 coins. So, dp[i][i] = {coins[i], 0}. Ex: Consider vector of coins [4], assuming player 1 plays first, all 4 coins are their's and player 2 will get 0.
Otherwise, dp[i][j].first means player 1's profit at cell i, j = max(coins[i] + dp[i+1][j].second, coins[j] + dp[i][j-1]). Ex: coins = [4, 9, 6], player 1's profit here will be max of, 4 + (what player 2nd would get from [9, 6])  or 6 + (what player 2nd would get from [4, 9]) = max(4 + 6, 6 + 4) = 10.
And, dp[i][j].second means player 2's profit at cell i, j = min(dp[i+1][j].first, dp[i][j-1].first)

DP table for coins = [4, 6, 2, 3]:

      0       1       2       3
0   (4,0)   (6,4)   (6,6)   (9,6)                                       A  B
1   (0,0)   (6,0)   (6,2)   (8,3)       --> Final answer is dp[0][3] = (9, 6)
2   (0,0)   (0,0)   (2,0)   (3,2)
3   (0,0)   (0,0)   (0,0)   (3,0)

*/
