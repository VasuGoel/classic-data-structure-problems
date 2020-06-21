#include <bits/stdc++.h>
using namespace std;

// Kadane's algorithm. O(n) time, O(1) space
int maxSumSubarray(vector<int> nums) {
    int sum = 0, res = INT_MIN;

    for(int x: nums) {
        sum += x;
        res = max(res, sum);
        sum = max(sum, 0);
    }
    return res;
}

int main() {
    vector<int> nums {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSumSubarray(nums) << endl;

    return 0;
}
