#include <bits/stdc++.h>
using namespace std;

// keeping length greater than width as a rule of generality, following are the rotations of rectangular box 
void generateRotations(vector<vector<int>> dims, vector<vector<int>> &boxes) {
    for(auto d: dims) {
        // max(l, w), min(l, w), h
        boxes.push_back({max(d[0], d[1]), min(d[0], d[1]), d[2]});
        // max(l, h), min(l, h), w
        boxes.push_back({max(d[0], d[2]), min(d[0], d[2]), d[1]});
        // max(w, h), min(w, h), l
        boxes.push_back({max(d[1], d[2]), min(d[1], d[2]), d[0]});
    }
}

// DP. O(n^2) times, O(n) space
int maxHeight(vector<vector<int>> dims) {
    vector<vector<int>> boxes;
    generateRotations(dims, boxes);     // get all box rotations

    // sort boxes based on increasing base area
    sort(boxes.begin(), boxes.end(), [&](auto a, auto b) -> bool {
        return a[0] * a[1] < b[0] * b[1];
    });

    int n = boxes.size();
    vector<int> dp(n);

    for(int i = 0; i < n; i++)  dp[i] = boxes[i][2];    // each box would at least have max height as its own height

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            // if smaller box has length and width strictly less than bigger box, the max height of bottom box will update to (bottom box height) + (max height at above box)
            if(boxes[j][0] < boxes[i][0] and boxes[j][1] < boxes[i][1])     dp[i] = max(dp[i], boxes[i][2] + dp[j]);
        }
    }
    return dp[n-1];
}

int main() {
    vector<vector<int>> dims {{1, 2, 4}, {3, 2, 5}};
    cout << maxHeight(dims) << endl;

    return 0;
}

/*

In this problem, we have to stack boxes with dimensions (l , w, h) on top of each other to maximize height, with a constraint that length and width of box on top must be strictly less than length and height of bottom box
and we can use multiple instances of same box (by rotating to use any side as base).

To solve this, we'll first list out all rotations of all boxes. For a box with dimension (l, w, h), keeping the length greater than width (as a rule of generality as it wouldn't affect the result) we get three rotations, i.e
1. max(l, w), min(l, w), h
2. max(l, h), min(l, h), w
3. max(w, h), min(w, h), l

For boxes with dims {1, 2, 4} and {3, 2, 5}, possible rotations are, 
                    2  1  4        3  2  5
                    4  1  2        5  3  2      -> Notice l > w for all dimensions for simplicty
                    4  2  1        5  2  3

Intuitively to get optimal height tower, the lower boxes should have greter base areas. So, we sort these boxes based on increasing base areas (l * w)
0   ->  2 1 4   -> smallest base
1   ->  4 1 2
2   ->  3 2 5
3   ->  4 2 1
4   ->  5 2 3
5   ->  5 3 2   -> largest base

boxes:  0   1   2   3   4   5
dp:     4   2   9   5   7   11      -> max height: 11

We can get max height of 11, if we stack boxes like,
2   1   4   -> smallest base
3   2   5
5   3   2   -> largest base
    
*/
