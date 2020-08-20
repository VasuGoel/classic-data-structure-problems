#include <bits/stdc++.h>
using namespace std;

// O(2^n) time, O(n) space
bool kPartition(vector<int> nums, int k, int index, vector<int> &chosen, int sum, int target) {
    if(k == 1)  return true;
    if(sum == target)   return kPartition(nums, k-1, 0, chosen, 0, target);
    if(sum > target)    return false;

    for(int i = index; i < nums.size(); i++) {
        if(!chosen[i]) {
            chosen[i] = k;  // mark this item for bucket k
            if(kPartition(nums, k, i+1, chosen, sum+nums[i], target))   return true;

            chosen[i] = 0;  // if above recursive call returns false, mark this item as not chosen
        }
    }
    return false;
}

vector<vector<int>> kPartition(vector<int> nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    // check to make sure vector can be partitioned into k subsets with equal sum (using all elements)
    if(k == 0 || total % k != 0)    return {};

    vector<int> chosen(nums.size());    // to mark an item was chosen for certain bucket/subset in a recursive call
    // if vector can be partitioned in k subsets of equal sum
    if(kPartition(nums, k, 0, chosen, 0, total/k)) {
        vector<vector<int>> res(k);
        // put items with same bucket number together
        for(int i = 0; i < nums.size(); i++) {
            int group = (chosen[i] == 0) ? 0 : chosen[i]-1;
            res[group].push_back(nums[i]);
        }
        return res;
    }
    return {};  // else return empty vector
}

int main() {
    vector<int> nums {7,3,5,12,2,1,5,3,8,4,6,4};
    int k = 3;

    for(vector<int> p: kPartition(nums, k)) {
        for(int x: p)   cout << x << " ";
        cout << endl;
    }
    return 0;
}

/*

K-Partition problem is a slight variation of 3-Partiton problem. For above example k = 3, so items are chosen such that each bucket/subset has sum = total/k

Starting with k = 3, 'chosen' vector is filled with chosen[i] = k, for item i recursively upto bucket k = 1 (not including it) since that means we're left with only 1 bucket to fill
and since we checked that total sum of elements is divisble by k, it means that last bucket will for sure have sum = total/k. So, it is sufficient to fill k-1 buckets as we know last bucket will also have equal sum
because we checked (total % k == 0) before partitioning

nums:   7   3   5   12  2   1   5   3   8   4   6   4 
chosen: 3   3   3   2   3   0   0   3   2   0   0   0 

subset: 0 -> 1 5 4 6 4
        1 -> 12 8
        2 -> 7 3 5 2 3 

*/
