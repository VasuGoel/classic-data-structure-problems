#include <bits/stdc++.h>
using namespace std;

// Using Bit Masking. O(n*2^n) time, O(1) space
bool subsetSum(vector<int> nums, int k) {
    int n = nums.size();
    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for(int bit = 0; bit < n; bit++) {
            if(mask & (1 << bit))   sum += nums[bit];
        }
        if(sum == k)    return true;
    }
    return false;
}

// DP. O(n^2) time, O(n^2) space
bool subsetSum(vector<int> nums, int k) {
    int m = nums.size();
    vector<vector<bool>> dp(m+1, vector<bool>(k+1));

    for(int i = 0; i <= m; i++)     dp[i][0] = 1;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= k; j++) {
            if(j < nums[i-1])   dp[i][j] = dp[i-1][j];
            else    dp[i][j] = dp[i-1][j] | (dp[i-1][j-nums[i-1]]);
        }
    }
    return dp[m][k];
}

int main() {
    vector<int> nums {2,3,7,8,10};
    int k = 14;
    
    if(subsetSum(nums, k))  cout << "Subset with sum exists\n";
    else    cout << "Subset with sum does not exists\n";

    return 0;
}
