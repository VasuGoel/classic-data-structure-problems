#include <bits/stdc++.h>
using namespace std;

// BFS (always helps to find min moves or paths to get to destination). O(n) time, O(n) space
int minMovesSnakeAndLadder(vector<int> moves, vector<bool> visited) {
    int n = moves.size()-1;     // number of cells in board
    
    // queue to hold pairs of cell number and min moves to get there
    queue<pair<int, int>> q;
    q.push({0, 0});     // start with cell 0 (doesn't exist) with min moves 0

    while(!q.empty()) {
        // get first pushed cell in queue and pop it
        auto curr = q.front();
        q.pop();

        // if reached the last cell return min moves to get there
        if(curr.first == n)     return curr.second;

        // at each cell we can get to next 6 consecutive cells
        for(int i = curr.first+1; i <= curr.first+6 && i <= n; i++) {
            // don't include neighboring cell if we've already pushed it into queue
            if(!visited[i]) {
                visited[i] = 1;     // mark cell visited

                // if there's no ladder or snake at this cell simply push into queue with new min moves
                if(!moves[i])   q.push({i, curr.second+1});
                // if there's ladder at this cell push ladder destination cell number with new min moves, also don't even push cells with snakes
                else if(moves[i] > i)    q.push({moves[i], curr.second+1});
            }
        }
    }
    return -1;
}

int main() {
    int n = 30;
    vector<int> moves(n+1);

    // ladders
    moves[3] = 22;
    moves[5] = 8;
    moves[11] = 26;
    moves[20] = 29;

    // snakes
    moves[17] = 4;
    moves[19] = 7;
    moves[21] = 9;
    moves[27] = 1;

    cout << minMovesSnakeAndLadder(moves, vector<bool>(n+1)) << endl;
    return 0;
}

/*

Check out board: https://media.geeksforgeeks.org/wp-content/uploads/snake-and-ladders.jpg

curr cell   neighbor    min moves  

0       1       1
0       2       1
0       22      1
0       4       1
0       8       1
0       6       1

1       7       2

2       8       2

22      23      2
22      24      2
22      25      2
22      26      2
22      26      2
22      28      2

4       9       2
4       10      2

8       26      2
8       12      2
8       13      2
8       14      2

23      29      3

24      30      3   <-- Final cell with min moves 3

9       15      3

10      16      3

12      16      3
12      18      3

13      18      3

14      29      3

------------------

30 - reached final cell with min moves 3

*/