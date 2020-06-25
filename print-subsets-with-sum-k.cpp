#include <bits/stdc++.h>
using namespace std;

// Recursive Approach. O(2^n) time, O(n) space
// At each node we can either add that number to subset or not
void subsetSum(vector<int> nums, int k, int i, int sum, vector<int> subset) {
    // when sum of subset equals k
    if(sum == k) {
        for(int x: subset)  cout << x << " ";
        cout << endl;
        return;
    }
    // when index or sum overshoots
    if(i == nums.size() || sum > k)     return;

    // add number to subset and recur further by adding it to sum
    subset.push_back(nums[i]);
    subsetSum(nums, k, i+1, sum+nums[i], subset);

    // remove last number from subset and recur without including it it sum
    subset.pop_back();
    subsetSum(nums, k, i+1, sum, subset);
}


// recursive function to find subsets with given sum using dp table
void findSubsets(vector<int> &nums, vector<vector<bool>> &dp, int i, int j, int k, int sum, vector<int> subset, vector<vector<int>> &res) {
    // if subset sum equals k, store it in results
    if(sum == k) {
        res.push_back(subset);
        return;
    }
    // invalid indices or sum
    if(i <= 0 || j <= 0 || sum > k)     return;

    // if given sum can be obtained by not including current element (after this recursive call returns, control moves to outside if condition and this item will be included in subset and recursion would take place)
    if(dp[i-1][j] == dp[i][j])  findSubsets(nums, dp, i-1, j, k, sum, subset, res);

    // include current element in subset and recur for remaining elements
    subset.push_back(nums[i-1]);
    sum += nums[i-1];
    findSubsets(nums, dp, i-1, k-sum, k, sum, subset, res);
}

// DP. O(n*k) time, O(n*k) space (Usual DP to find subsets with equal sum)
vector<vector<int>> subsetSum(vector<int> nums, int k) {
    int n = nums.size();
    vector<vector<bool>> dp(n+1, vector<bool>(k+1));

    for(int i = 0; i <= n; i++)     dp[i][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j < nums[i-1])   dp[i][j] = dp[i-1][j];
            else    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
        }
    }

    // recursively find subsets using dp table and store in res
    vector<vector<int>> res;
    findSubsets(nums, dp, n, k, k, 0, vector<int>(), res);
    return res;
}


int main() {
    vector<int> nums {1, 2, 3, 4, 5, 6, 7};
    int k = 12;

    // recursive approach
    // subsetSum(nums, k, 0, 0, vector<int>());     

    // dp approach
    for(vector<int> s: subsetSum(nums, k)) {
        for(int x: s)   cout << x << " ";
        cout << endl;
    }
    return 0;
}
