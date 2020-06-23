#include <bits/stdc++.h>
using namespace std;

// Backtracking. O(2^n) time, O(1) space
bool backtrack(vector<int> nums, int i, int sum, int total) {
    // if sum so far equals half the total sum of vector then it can be partitioned into equal subsets
    if(sum == total/2)    return true;
    // if sum or index in vector overshoots
    if(sum > total/2 || i == nums.size()) return false;

    // try all combinations, including current element in sum and not including it
    return backtrack(nums, i+1, sum+nums[i], total) || backtrack(nums, i+1, sum, total);
}

bool canPartition(vector<int> nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    // if total of vector is odd then it cannot be partitioned into 2 subsets with equal sum
    if(total & 1 == 1)    return false;

    return backtrack(nums, 0, 0, total);
}



// Backtracking - Another approach. O(2^n) time, O(n) space
bool backtrack(vector<int> nums, int index, vector<bool> chosen, int sum, int total) {
    if(sum == total/2)    return true;
    if(sum > total/2 || index == nums.size()) return false;

    // iterate over all numbers starting from current index in recursion
    for(int i = index; i < nums.size(); i++) {
        // if current number is not chosen
        if(!chosen[i]) {
            chosen[i] = 1;  // choosen number
            // recur with next index and current num added to sum
            if(backtrack(nums, index+1, chosen, sum+nums[i], total))    return true;

            // if above recursive call returns false unchoose current number (to be used by other recursive calls now) and try next
            chosen[i] = 0;
        }
    }
    return false;
}

bool canPartition(vector<int> nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if(total & 1 == 1)    return false;

    return backtrack(nums, 0, vector<bool>(nums.size()), 0, total);
}



// DP. O(n^2) time, O(n^2) space
bool subsetSum(vector<int> nums, int k) {
    int m = nums.size();
    vector<vector<bool>> dp(m+1, vector<bool>(k+1));

    for(int i = 0; i <= m; i++)     dp[i][0] = 1;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= k; j++) {
            if(j < nums[i-1])   dp[i][j] = dp[i-1][j];
            else    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
        }
    }
    return dp[m][k];
}

bool canPartition(vector<int> nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    // if total of vector is odd then it cannot be partitioned into 2 subsets with equal sum
    if(total & 1 == 1)    return false;

    // return true if there's a subset with half the total sum (means there are 2 subsets with equal sum)
    return subsetSum(nums, total/2);
}

int main() {
    vector<int> nums {1, 5, 11, 5};

    if(canPartition(nums))  cout << "Can be partitioned into subsets with equal sum\n";
    else    cout << "Cannot be partitioned into subsets with equal sum\n";

    return 0;
}
