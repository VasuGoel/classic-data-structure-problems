#include <bits/stdc++.h>
using namespace std;

// Single Pass. O(n) time, O(1) space
void sortNums(vector<int> &nums) {
    int l = 0, r = nums.size()-1, i = 0;

    while(i <= r) {
        if(nums[i] == 0)    swap(nums[i++], nums[l++]);
        else if(nums[i] == 2)   swap(nums[i], nums[r--]);
        else    i++;
    }
}

// Two Pass. O(n) time, O(1) space
void sortNums(vector<int> &nums) {
    vector<int> freq(3);
    for(int x: nums)    freq[x]++;

    int i = 0;
    while(freq[0]--)    nums[i++] = 0;
    while(freq[1]--)    nums[i++] = 1;
    while(freq[2]--)    nums[i++] = 2;
}

int main() {
    vector<int> nums {0,1,2,2,1,0,0,2,0,1,1,0};

    sortNums(nums);
    for(int x: nums)  cout << x << " "; cout << endl;

    return 0;
}
