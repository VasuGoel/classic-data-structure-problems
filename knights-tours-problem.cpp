#include <bits/stdc++.h>
using namespace std;

// check if knight can be placed on cell (i, j)
bool validKnight(vector<vector<int>> &board, int i, int j) {
    int n = board.size();
    // handles out of bounds and checks if cell is not already visited
    if(i < 0 || i >= n || j < 0 || j >= n || board[i][j])   return false;
    return true;
}

// recursively call tour (dfs) on valid board cells to return all possible knights tours
void tour(vector<vector<int>> &board, int i, int j, int move, vector<pair<int,int>> &dirs) {
    board[i][j] = move;     // mark cell as visited by storing move number

    int n = board.size();
    // if at the last move, print the board and continue along dfs (for printing all possible tours)
    if(move == n*n) {
        for(auto r: board) {
            for(int c: r)   cout << c << '\t'; cout << endl;
        }
        cout << endl;
    }
    
    // for all 8 possible moves of a knight
    for(auto dir: dirs) {
        int new_i = i + dir.first, new_j = j + dir.second;      // find new cell by adding offsets
        // check if new cell is valid and recur on this new cell for the next move
        if(validKnight(board, new_i, new_j))    tour(board, new_i, new_j, move+1, dirs);
    }
    board[i][j] = 0;    // backtrack from current cell and remove it from current path
}

void knightsTour(int n, pair<int,int> src) {
    vector<vector<int>> board(n, vector<int>(n));       // 2d chess board with all zeroes
    // offsets for all 8 possible moves of a knights
    vector<pair<int,int>> dirs {{-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    tour(board, src.first, src.second, 1, dirs);    // find all possible valid knights tours from source
}

int main() {
    int n = 5;
    pair<int,int> src = {0, 0};
    knightsTour(n, src);

    return 0;
}
