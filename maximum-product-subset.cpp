#include <bits/stdc++.h>
using namespace std;

// O(n) time, O(1) space
int maxProductSubset(vector<int> nums) {
    int prod = 1, max_neg = INT_MIN, neg_cnt = 0;
    // find max negative number and count number of negatives
    for(int x: nums)    if(x < 0)   max_neg = max(max_neg, x), neg_cnt++;

    // if number of negatives are even then change 'max_neg' to 1
    if(neg_cnt % 2 == 0)    max_neg = 1;
    
    // multiply each non-zero number in nums
    for(int x: nums)    if(x)   prod *= x;
    return prod / max_neg;
}

int main() {
    vector<int> nums {-6, 4, -5, 8, -10, 0, 8};
    cout << maxProductSubset(nums) << endl;

    return 0;
}

/*

To get maximum product among all subsets on 'nums', there's two important points to note:

1. 0 should not be included in product
2. Product of two -ve numbers is +ve. If number of negatives in 'nums' are even then all would contribute +ve product, else we need to not include the max negative number in final product

For nums:   -6, 4, -5, 8, -10, 0, 8
no. of negatives are 3 (odd) and max negative is -5

So, we'll divide -5 from final product of all non-zero numbers in 'nums': -76800 / -5 = 15360, giving us max product and the subset is {-6, 4, 8, -10, 8}

*/
