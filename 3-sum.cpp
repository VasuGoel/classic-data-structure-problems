#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>> res;
    for(int i = 0; i < n-2; i++) {
        if(i != 0 && nums[i] == nums[i-1])  continue;
    
        int l = i+1, r = n-1, comp = k-nums[i];
        while(l < r) {
            int sum = nums[l]+nums[r];
            if(sum == comp) {
                res.push_back({nums[i], nums[l], nums[r]});
                l++, r--;
                while(l < r && nums[l] == nums[l-1])    l++;
                while(l < r && nums[r] == nums[r+1])    r--;
            }
            else if(sum < comp) l++;
            else    r--;
        }
    }
    return res;
}

int main() {
    vector<int> nums {2,7,4,0,9,5,1,3};
    int k = 6;

    for(vector<int> r: threeSum(nums, k)) {
        cout << r[0] << " " << r[1] << " " << r[2] << endl;
    }
    return 0;
}
