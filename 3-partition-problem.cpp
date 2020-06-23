#include <bits/stdc++.h>
using namespace std;

// Backtracking. O(2^n) time, O(n) space
bool canPartition(vector<int> nums, int k, int index, vector<bool> chosen, int sum, int target) {
    // if 1 bucket is left to fill it means we've already filled k-1 buckets and since total was divisible by k then last bucket would for sure also contain sum total/k
    if(k == 1)  return true;

    // if one bucket is filled reduce bucket count to be filled and reset sum for next recursion
    if(sum == target)   return canPartition(nums, k-1, 0, chosen, 0, target);
    // if sum or index overshoots return false and don't recur further
    if(sum > target || index == nums.size())    return false;

    // iterate all nums starting from current index in recursion
    for(int i = index; i < nums.size(); i++) {
        // if num is not chosen in some bucket already
        if(!chosen[i]) {
            chosen[i] = 1;  // choose num for current bucket
            // now recur to check if we've reached target or exceeded it, and if none then try including next num in this bucket
            if(canPartition(nums, k, index+1, chosen, sum+nums[i], target))     return true;

            // if above recursive call returns false, remove this item from bucket (so it can be used in another bucket) and try next num
            chosen[i] = 0;
        }
    }
    return false;
}

bool partitionKSubsets(vector<int> nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    // if total is not divisible by k then nums cannot be divided into k subsets with equal sum
    if(k == 0 || total % k != 0)    return false;

    // simulate filling k buckets each with sum, total/k
    return canPartition(nums, k, 0, vector<bool>(nums.size()), 0, total/k);
}

int main() {
    vector<int> nums {7,8,2,1,5,4,3};
    int k = 3;

    if(partitionKSubsets(nums, k))    cout << "Can be partitioned into " << k << " subsets with equal sum\n";
    else    cout << "Cannot be partitioned into " << k << " subsets with equal sum\n";

    return 0;
}
