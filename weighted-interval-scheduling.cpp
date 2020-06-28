#include <bits/stdc++.h>
using namespace std;

// DP. O(n^2) time, O(n) space
int maxProfit(vector<vector<int>> intervals) {
    // sort intervals based on earliest finishing time
    sort(intervals.begin(), intervals.end(), [&](auto a, auto b) -> bool {
        return a[1] < b[1];
    });

    int n = intervals.size(), profit = INT_MIN;
    vector<int> dp(n);
    for(int i = 0; i < n; i++)  dp[i] = intervals[i][2];    // initial profits for all intervals

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            // if interval i and j don't overlap (or start time of interval i is more than finish time of interval j, note - intervals are sorted based on earliest finishing times)
            if(intervals[i][0] > intervals[j][1])   dp[i] = max(dp[i], intervals[i][2]+dp[j]);
        }
        profit = max(profit, dp[i]);    // update final profit
    }
    return profit;
}

int main() {
    vector<vector<int>> intervals {{0, 6, 60}, {1, 4, 30}, {3, 5, 10}, {5, 7, 30}, {5, 9, 50}, {7, 8, 10}};
    cout << maxProfit(intervals) << endl;

    return 0;
}

/*

To find max profit among all these intervals with start and finish times and profits associated with them, if we think of a greedy stategy like sort intervals based on decreasing profits
or based on earliest finishing times, its not hard to come up with counterexamples. Greedy works fine for Activity Selection problem since all intervals have equal weights but here it won't work
since even a single job may have more profit than all other jobs combined.


Dynamic Programming can be used to solve this, first sort intervals based on earliest finishing times then for each interval i check all intervals j, 0 ≤ j < i, if these intervals don't overlap
then dp[i] = max(dp[i], profit at interval i + dp[j]). Here, dp[i] is the max profit upto interval i.

Considering above example, all intervals in sorted order (based on earliest finishing times) are:

intervals:  (1, 4)  (3, 5)  (9, 6)  (5, 7)  (7, 8)  (5, 9)
initial dp:    30     30      60      30      10      50

final dp:      30     30      60      60      70      80

max profit among all intervals = 80

*/
