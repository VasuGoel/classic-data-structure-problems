#include <bits/stdc++.h>
using namespace std;

// O(n) time, O(n) space
vector<int> longestBitonicSubarray(vector<int> nums) {
    int n = nums.size(), len = 1;
    vector<int> lis(n, 1), lds(n, 1);

    // longest increasing subarray ending at index i
    for(int i = 1; i < n; i++) {
        if(nums[i] > nums[i-1])     len++;
        else    len = 1;
        lis[i] = len;
    }

    // longest decreasing subarray starting at index i
    len = 1;
    for(int i = n-2; i >= 0; i--) {
        if(nums[i+1] < nums[i])     len++;
        else    len = 1;
        lds[i] = len;
    }

    vector<int> lbs(n);

    // longest bitonic subarray is max of lis[i] + lds[i] - 1 for all i
    int mid = 0, maxlen = 1;
    for(int i = 0; i < n; i++) {
        lbs[i] = lis[i] + lds[i] - 1 ;
        if(lis[i] + lds[i] - 1 > maxlen) {
            maxlen = lis[i] + lds[i] - 1;
            mid = i;
        }
    }

    for(int x: lis) cout << x << "  "; cout << endl;
    for(int x: lds) cout << x << "  "; cout << endl;
    for(int x: lbs) cout << x << "  "; cout << endl;

    return {nums.begin()+mid-lis[mid]+1, nums.begin()+mid+lds[mid]};
}

int main() {
    vector<int> nums {3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4};
    
    for(int x: longestBitonicSubarray(nums)) cout << x << ' '; cout << endl;
    return 0;
}

/*

Longest bitonic subarray (lbs) of an array is the max of (longest increasing subarray (lis) ending at index i) + (longest decreasing subarray (lds) starting at index i) - 1, for all i

nums:   3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 
lis:    1  2  3  1  2  3  4   1  1  1  2    -> longest increasing subarray upto index i
lds:    1  1  2  1  1  1  4   3  2  1  1    -> longest decreasing subarray starting at index i
lbs:    1  2  4  1  2  3  7   3  2  1  2    -> longest bitonic subarray starting with mid at i

*/
