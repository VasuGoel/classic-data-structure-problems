#include <bits/stdc++.h>
using namespace std;

// O(n^4) time, O(n^2) space
int maxSumSubmatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> sum(m, vector<int>(n));

    // preprocess to get sum matrix
    sum[0][0] = matrix[0][0];
    for(int j = 1; j < n; j++)  sum[0][j] = sum[0][j-1] + matrix[0][j];
    for(int i = 1; i < n; i++)  sum[i][0] = sum[i-1][0] + matrix[i][0];

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    int res = INT_MIN;
    // check sum of every submatrix (constant time due to preprocessing) starting from row x1 to x2 and column y1 to y2
    for(int x1 = 0; x1 < m; x1++) {
        for(int x2 = x1; x2 < m; x2++) {
            for(int y1 = 0; y1 < n; y1++) {
                for(int y2 = y1; y2 < n; y2++) {
                    int total = sum[x2][y2];
                    if(x1-1 >= 0)   total -= sum[x1-1][y2];
                    if(y1-1 >= 0)   total -= sum[x2][y1-1];
                    if(x1-1 >= 0 && y1-1 >= 0)  total += sum[x1-1][y1-1];
                    
                    res = max(res, total);
                }
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> matrix {{-5, -6, 3, 1, 0}, {9, 7, 8, 3, 7}, {-6, -2, -1, 2, -4}, {-7, 5, 5, 2, -6}, {3, 2, 9, -5, 1}};

    cout << maxSumSubmatrix(matrix) << endl;
    return 0;
}

/*

-5  -6   3   1   0
 9   7   8   3   7          7   8   3
-6  -2  -1   2  -4  -->    -2  -1   2   --> sum = 35
-7   5   5   2  -6          5   5   2
 3   2   9  -5   1          2   9  -5

*/
