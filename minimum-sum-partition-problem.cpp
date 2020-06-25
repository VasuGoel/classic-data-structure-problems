#include <bits/stdc++.h>
using namespace std;

// Usual DP to find subset sum upto k
void subsetSum(vector<int> nums, int k, vector<vector<bool>> &dp) {
    int n = nums.size();

    for(int i = 0; i <= n; i++)     dp[i][0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j < nums[i-1])   dp[i][j] = dp[i-1][j];
            else    dp[i][j] = dp[i-1][j] | dp[i-1][j-nums[i-1]];
        }
    }
}

// DP. O(n^2) time, O(n^2) space
int minSumPartitionProblem(vector<int> nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size(), k = total/2;
    vector<vector<bool>> dp(n+1, vector<bool>(k+1));
    
    subsetSum(nums, k, dp);

    int closest = 0;
    // find first 1 in last row starting from bottom right
    for(int j = k; j >= 0; j--) {
        if(dp[n][j] == 1) {
            closest = j; 
            break;
        }
    }
    return abs((total - closest) - closest);
}

int main() {
    vector<int> nums {10, 20, 15, 5, 25};

    cout << minSumPartitionProblem(nums) << endl;
    return 0;
}

/*

We have to divide vector into 2 parts/subsets so that absolute difference of sum of elements in these 2 partitions is minimum. An ideal case, would be if vector could be divided into 2 subsets with equal sum (partition problem)
in that case, absolute difference between sum of those 2 subsets would be 0. 
We can leverage that idea to find the minimum sum closest to (sum of elements in vector) / 2, in which vector can be partitioned and it would guarantee absolute difference between sum of those subsets would be min.

Consider elements [10, 20, 15, 5, 25], with total = 75. Here, min sum partition would be 5 when vector is partitioned as [10, 20, 5], [15, 25] (or [10, 25], [20, 15, 5])
We can set k = 75/2 = 37 and use DP to find subset sum

    0  1  2  3  4  5  6  7  8  9 10  ...................................................................  34 35 36 37
0   1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
10  1  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  
20  1  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0  
15  1  0  0  0  0  0  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  
5   1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  
25  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  0  0  1  0  0  
                                                                                                             •      

From the DP table, it it clear that 35 is closest to 37 in which vector can be partitoned. Hence, min sum = |(total - 35) - 35|= 5, where 35 is sum of one partition and (total - 35) is sum of the other partition

*/
