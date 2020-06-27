#include <bits/stdc++.h>
using namespace std;

// O(n) time, O(1) space
vector<int> longestIncreasingSubarray(vector<int> nums) {
    int n = nums.size(), end = 0, len = 1, maxlen = 1;

    for(int i = 1; i < n; i++) {
        if(nums[i] > nums[i-1])     len++;
        else    len = 1;

        if(len > maxlen) {
            maxlen = len;
            end = i;
        }
    }
    return {nums.begin()+end-maxlen+1, nums.begin()+end+1};
}

int main() {
    vector<int> nums {2, 1, 2, 5, 7, 9, 1, 4};

    for(int x: longestIncreasingSubarray(nums))     cout << x << " "; cout << endl;
    return 0;
}

/*

nums:   2  1  2  5  7  9  1  4
len:    1  1  2  3  4  5  1  2
maxlen: 1  1  2  3  4  5  5  5
end:    0  0  2  3  4  5  5  5

*/
