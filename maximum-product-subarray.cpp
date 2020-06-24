#include <bits/stdc++.h>
using namespace std;

// O(n) time, O(1) space
int maxProductSubarray(vector<int> nums) {
    int max_sf = 0, min_sf = 0, maxprod = 0;

    for(int i = 0; i < nums.size(); i++) {  
        // store max_sf and min_sf to avoid discrepancy when min_sf is calculated after max_sf has been updated just above
        int curr_max = max_sf, curr_min = min_sf;

        max_sf = max({nums[i], curr_max*nums[i], curr_min*nums[i]});
        min_sf = min({nums[i], curr_max*nums[i], curr_min*nums[i]});

        maxprod = max(maxprod, max_sf);
    }
    return maxprod;
}

int main() {
    vector<int> nums {-6, 4, -5, 8, -10, 0, 8};
    cout << maxProductSubarray(nums) << endl;

    return 0;
}

/*

nums:           -6     4     -5     8     -10     0     8

max so far:      0     4     120   960    1600    0     8
min so far:     -6    -24    -20  -160   -9600    0     0

maxprod:         0     4     120   960    1600   1600  1600

*/
