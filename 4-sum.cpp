#include <bits/stdc++.h>
using namespace std;

// Two-pointer approach. O(n^3) time, O(1) space
vector<vector<int>> fourSum(vector<int> nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for(int i = 0; i < n-3; i++) {
        if(i != 0 && nums[i] == nums[i-1])  continue;

        for(int j = i+1; j < n-2; j++) {
            if(j != i+1 && nums[j] == nums[j-1])    continue;

            int comp = k - (nums[i] + nums[j]), l = j+1, r = n-1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum == comp) {
                    res.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++, r--;
                    while(l < r && nums[l] == nums[l-1])    l++;
                    while(l < r && nums[r] == nums[r+1])    r--;
                }
                else if(sum < comp) l++;
                else    r--;
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums {2, 7, 4, 0, 9, 5, 1, 3};
    int k = 20;

    for(vector<int> r: fourSum(nums, k)) {
        cout << r[0] << " " << r[1] << " " << r[2] << " " << r[3] << endl;
    }
    return 0;
}
