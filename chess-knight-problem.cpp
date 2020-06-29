#include <bits/stdc++.h>
using namespace std;

// BFS. O(n^2) time, O(n^2) space
int minMoves(int n, pair<int,int> src, pair<int,int> dst) {
    vector<vector<bool>> visited(n, vector<bool>(n));   // cell once visited should not be pushed in queue again

    // knight has max 8 possible moves at any cell, which can be computed by adding these offsets to current cell
    vector<pair<int,int>> dirs {{-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    // lambda to check if a cell is inside the n x n chess board
    auto inside = [&](pair<int,int> a) -> bool {
        return a.first >= 0 && a.first < n && a.second >= 0 && a.second < n;
    };

    // queue to hold vectors of integers, index i and j and min moves to get to that cell in board
    queue<vector<int>> q;
    q.push({src.first, src.second, 0});     // push source cell in queue
    visited[src.first][src.second] = 1;     // mark source as visited

    while(!q.empty()) {
        // pull out and store first cell from queue and remove it
        int curr_i = q.front()[0], curr_j = q.front()[1], moves = q.front()[2];
        q.pop();

        // if at the last cell return min moves to get there
        if(make_pair(curr_i, curr_j) == dst)    return moves;

        // compute all valid moves for a knight at cell (curr_i, curr_j) by adding offsets in 'dirs'
        for(auto dir: dirs) {
            int new_i = curr_i + dir.first, new_j = curr_j + dir.second;

            // if the new cell is inside the board and not visited mark it visited and add to queue for exploration
            if(inside({new_i, new_j}) and !visited[new_i][new_j]) {
                visited[new_i][new_j] = 1;
                q.push({new_i, new_j, moves+1});
            }
        }
    }
    throw runtime_error("No possible moves");
}

int main() {
    int n = 8;
    pair<int,int> src = {7, 0}, dst = {0, 7};
    cout << minMoves(n, src, dst) << endl;

    return 0;
}

// Check out board at: https://imgur.com/a6lKld8
