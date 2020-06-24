#include <bits/stdc++.h>
using namespace std;

// O(n) time, O(1) space
vector<int> longestAlternatingSubarray(vector<int> nums) {
    // lambda to return 0 if number is -ve or 1 if +ve
    auto sign = [&](int a) -> int { return (a < 0) ? 0 : 1; };
    // c to keep track of what number to look for next, c = 0 means look for -ve, and c = 1 means look for +ve num next
    int cnt = 0, len = 0, endIndex = 0, c = sign(nums[0]);

    for(int i = 0; i < nums.size(); i++) {
        if(sign(nums[i]) == c)    cnt++;
        else {
            cnt = 1;
            c = sign(nums[i]);      // reset sign to current nums sign
        }

        if(cnt > len) {
            len = cnt; endIndex = i;
        }
        c ^= 1;     // look for alternate sign
    }
    return {nums.begin()+endIndex-len+1, nums.begin()+endIndex+1};
}

int main() {
    vector<int> nums {1, -2, 6, 4, -3, 2, -4, -3};

    for(int x: longestAlternatingSubarray(nums))    cout << x << " "; cout << endl;
    return 0;
}

/*
                                        --------------------------
nums:           1       -2      6       4       -3      2       -4      -3

longest
alternating     1       2       3       1        2      3        4       1
subarray:

*/
