#include <bits/stdc++.h>
using namespace std;

// O(n) time, O(n) space
int longestConsecutiveSubsequence(vector<int> nums) {
    unordered_set<int> s;
    for(int x: nums)    s.insert(x);

    int len = 0, y;
    for(int x: nums) {
        if(s.find(x-1) == s.end()) {
            y = x+1;
            while(s.find(y) != s.end())     y++;
            len = max(len, y-x);
        }
    }
    return len;
}

int main() {
    vector<int> nums {2, 0, 6, 1, 5, 3, 7};
    cout << longestConsecutiveSubsequence(nums) << endl;

    return 0;
}

/*

Longest consecutive subsequence in [2, 0, 6, 1, 5, 3, 7] is [2, 0, 1, 3].
To solve this, put all number in a hash-set and for every number in nums check if x-1 is present in the hash-set or not, and for the first x for which x-1 is not in hash-set for ex: 0 or 5 in above example
check y = x+1, x+2, ... until y is not present in hash-set. The difference y-x is the amount of consecutive number present in hash-set and update 'len' if greater length of subsequence is found. We're essentially
walking down a streak only once per streak, hence the time complexity is linear.

*/
