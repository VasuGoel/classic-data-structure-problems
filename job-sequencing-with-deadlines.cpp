#include <bits/stdc++.h>
using namespace std;

// Greedy Approach. O(n^2) time, O(n) space
int jobSequencingDeadlines(vector<vector<int>> &jobs) {
    int max_deadline = INT_MIN;
    for(auto j: jobs)   max_deadline = max(max_deadline, j[1]);
    vector<int> slots(max_deadline);
    
    // sort jobs in decreasing order of profits
    sort(jobs.begin(), jobs.end(), [&](auto a, auto b) {
        return a[2] > b[2];
    });

    int profit = 0;
    // for each job
    for(vector<int> job: jobs) {
        // find an empty slot (with 0) before job's deadline (index)
        for(int i = job[1]-1; i >= 0; i--) {
            if(slots[i] == 0) {
                slots[i] = job[0];
                profit += job[2];
                break;
            }
        }
    }

    cout << "Job numbers of jobs scheduled are: ";
    for(int x: slots)   if(x)   cout << x << " ";
    cout << "\nMaximum Profit: ";

    return profit;
}

int main() {
    vector<vector<int>> jobs {{1,9,15}, {2,2,2}, {3,5,18}, {4,7,1}, {5,4,25}, {6,2,20}, {7,5,8}, {8,7,10}, {9,4,12}, {10,3,5}};

    cout << jobSequencingDeadlines(jobs) << endl;
    return 0;
}

/*

Original Jobs       Jobs sorted based on max profits
1  9  15                5  4  25
2  2  2                 6  2  20
3  5  18                3  5  18
4  7  1                 1  9  15
5  4  25    -->         9  4  12
6  2  20                8  7  10
7  5  8                 7  5  8
8  7  10                10 3  5
9  4  12                2  2  2
10 3  5                 4  7  1

Consider deadline slots: 0 __ 1 __ 2 __ 3 __ 4 __ 5 __ 6 __ 7 __ 8 __ 9
Starting with job with max profit we keep filling these deadline slots and if a job cannot be filled in any slots before deadline
(means all slots are filled before this deadline and they are guaranteed to have greater or equal profits) we don't consider this job in profits and skip it

Above jobs can be filled in this way (starting with job with max profit),

   7   6    9     5    3   4    8          1        <-- Job number
0 __ 1 __ 2 __ 3 __ 4 __ 5 __ 6 __ 7 __ 8 __ 9      <-- Deadline

*/
