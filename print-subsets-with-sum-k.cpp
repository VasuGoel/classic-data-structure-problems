#include <bits/stdc++.h>
using namespace std;

// O(2^n) time, O(n) space
// At each node we can either add that number to subset or not
void subsetSum(vector<int> nums, int k, int i, int sum, vector<int> &subset) {
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

int main() {
    vector<int> nums {1, 2, 3, 4, 5, 6, 7};
    int k = 12;

    vector<int> subset;
    subsetSum(nums, k, 0, 0, subset);
    return 0;
}
