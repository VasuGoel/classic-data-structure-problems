#include <bits/stdc++.h>
using namespace std;

// Greedy Approach. O(nlogn) time, O(n) space
vector<pair<int, int>> maxActivities(vector<pair<int, int>> intervals) {
    // sort intervals based on earliest finish times
    sort(intervals.begin(), intervals.end(), [&](auto a, auto b) -> bool {
        return a.second < b.second;
    });

    vector<pair<int, int>> res;     // stores final intervals of activities
    res.push_back(intervals[0]);    // push first activity (earliest finish time) into res

    // interval scheduling
    for(int i = 1; i < intervals.size(); i++) {
        // if start time of this activity is greater than finish time of last activity in res, add it into res
        if(intervals[i].first > res.back().second)  res.push_back(intervals[i]);
    }
    return res;
}

int main() {
    vector<pair<int, int>> intervals = {{1, 4}, {4, 4}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};

    for(auto p: maxActivities(intervals))   cout << p.first << " " << p.second << endl;
    return 0;
}
