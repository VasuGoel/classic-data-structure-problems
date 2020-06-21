#include <bits/stdc++.h>
using namespace std;

// Using hash table. O(n) time, O(n) space
vector<int> twoSum(vector<int> nums, int k) {
    unordered_map<int, int> dict;

    for(int i = 0; i < nums.size(); i++) {
        int comp = k-nums[i];
        if(dict.find(comp) != dict.end())   return {dict[comp], i};
        
        dict[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums {8,7,2,5,3,1};
    int k = 10;

    vector<int> res = twoSum(nums, k);
    if(!res.empty())    cout << res[0] << " " << res[1] << endl;
    else    cout << "No such pair\n";

    return 0;
}
