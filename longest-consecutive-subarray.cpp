#include <bits/stdc++.h>
using namespace std;

// O(n^2) time, O(n) space
vector<int> longestSubarrayConsecutiveElements(vector<int> nums) {
    int n = nums.size(), len = INT_MIN, start = 0;

    for(int i = 0; i < n; i++) {
        unordered_set<int> s;
        int maxi = nums[i], mini = nums[i];

        for(int j = i; j < n; j++) {
            if(s.find(nums[j]) != s.end())  break;
            
            s.insert(nums[j]);
            maxi = max(maxi, nums[j]), mini = min(mini, nums[j]);
            if(j-i+1 == maxi-mini+1 && j-i+1 > len) {
                len = j-i+1;
                start = i;
            }
        }
    }
    return {nums.begin()+start, nums.begin()+start+len};    // return longest subarray starting at index 'start' and of length 'len'
}

int main() {
    vector<int> nums {2,0,2,1,4,3,1,0};
    
    for(int x: longestSubarrayConsecutiveElements(nums))    cout << x << " "; cout << endl;
    return 0;
}

/*

A subarray can have consecutive elements when difference between max and min in that subarray equals the length of that subarray iff there's distinct elements in subarray.
But in this problem, duplicates exists so we use hashset to keep track of already used elements.

For every i, 0 ≤ i < n, we iterate over j, i ≤ j < n and if a duplicate is found we break that inner iteration but all the while maintaining the length of longest subarray.

            i
Consider [2,0,2,1,4,3,1,0], for i = 1 from j = 1 to j = 5, hashset would contain {0,2,1,4,3} (without any specific order) and maxi = 4 and mini = 0 and len = j-i+1 = 5 = maxi-mini+1 = 5
            j       j
*/
