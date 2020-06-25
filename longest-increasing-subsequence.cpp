#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n) space
int longestIncreasingSubsequence(vector<int> nums) {
    int n = nums.size(), len = 1;
    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i])   dp[i] = max(dp[i], 1 + dp[j]);
            len = max(len, dp[i]);
        }
    }
    return len;
}

// Binary Search Approach. O(nlogn) time, O(n) space
int longestIncreasingSubsequence(vector<int> nums) {
    vector<int> res;
    for(int x: nums) {
        auto itr = lower_bound(res.begin(), res.end(), x);
        if(itr == res.end())    res.push_back(x);
        else    *itr = x;
    }
    return (int)res.size();
}

int main() {
    vector<int> nums {1, 0, 2, 8, 3, 4, 5, 10, 6, 1, 2};
    cout << longestIncreasingSubsequence(nums) << endl;

    return 0;
}

/*

In DP approach, dp[i] denotes, longest increasing subsequence when num i is included in seq.
For num at i, 0 ≤ i < n, check every j, 0 ≤ j < i and if nums[j] < nums[i], then dp[i] = max(dp[i], 1 + dp[j])
 
nums:   1, 0, 2, 8, 3, 4, 5, 10, 6, 1, 2
lis:    1  1  2  3  3  4  5  6   6  2  3 

*/
