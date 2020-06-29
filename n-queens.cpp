#include <bits/stdc++.h>
using namespace std;

// check if current queen placement is valid, O(n) time
bool validQueen(int n, vector<int> cols) {
    int row = cols.size()-1;
    // loop through all queen placements before current queen
    for(int i = 0; i < row; i++) {
        // if current queen is placed in the same column as queen in row i or if they're diagonal then current queen's placement is invalid
        if(cols[i] == cols[row] || (abs(i - row) == abs(cols[i] - cols[row])))  return false;
    }
    return true;
}

// recursive function to solve for row i
void solve(int n, int row, vector<int> cols, vector<vector<int>> &pos) {
    // if reached the last row, push current queen placements in 'cols' to 'pos' result vector
    if(row == n) {
        pos.push_back(cols);
        return;
    }

    // try placing queen for row 'row' in column 'c'
    for(int c = 0; c < n; c++) {
        cols.push_back(c);  // place queen
        if(validQueen(n, cols))   solve(n, row+1, cols, pos);       // check if this current placed queen has valid position, if true then recursively solve for next row

        cols.pop_back();    // undo this position if invalid (above recursive call won't happen means we won't move to next row but try placing queen in another column)
    }
}

// O(n*2^n) time, O(n) space
vector<vector<int>> nQueens(int n) {
    vector<vector<int>> pos;
    solve(n, 0, vector<int>(), pos);
    return pos;
}

int main() {
    int n = 4;

    for(auto queens: nQueens(n)) {
        for(int col: queens)    cout << col << ' '; cout << endl;
    }
    return 0;
}
