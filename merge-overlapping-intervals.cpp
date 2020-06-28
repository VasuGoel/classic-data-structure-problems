#include <bits/stdc++.h>
using namespace std;

// O(nlogn) time, O(1) space
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals)  {
    // sort intervals based on earliest start time
    sort(intervals.begin(), intervals.end(), [&](auto a, auto b) -> bool {
        return a.first < b.first;
    });
    
    vector<pair<int, int>> res;     // stores merged intervals
    // for each interval check if it overlaps with last interval in 'res'
    for(auto i: intervals) {
        // if 'res' is empty or this interval does not overlap with last interval in 'res', simpy add it
        if(res.empty() || i.first > res.back().second)  res.push_back(i);
        // if intervals overlap then update the finish time of last interval in 'res' if current interval has greater finish time
        else    res.back().second = max(res.back().second, i.second);
    }
    return res;
}

int main() {
    vector<pair<int, int>> intervals {{1, 5}, {2, 3}, {4, 6}, {7, 8}, {8, 10}, {12, 15}};
    for(auto p: mergeIntervals(intervals))  cout << p.first << ' ' << p.second << endl;

    return 0;
}
