#include <bits/stdc++.h>
using namespace std;

// O(mn) time, O(mn) space
int sumSubMatrix(vector<vector<int>> matrix, pair<int, int> tl, pair<int, int> br) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> sum(m, vector<int>(n));

    sum[0][0] = matrix[0][0];
    // preprocess first row
    for(int j = 1; j < n; j++)  sum[0][j] = sum[0][j-1] + matrix[0][j];
    // preprocess first column
    for(int i = 1; i < n; i++)  sum[i][0] = sum[i-1][0] + matrix[i][0];

    // preprocess rest of the matrix
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            sum[i][j] = matrix[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    int x1 = tl.first, y1 = tl.second, x2 = br.first, y2 = br.second;
    // return sum of required submatrix, sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]
    int total = sum[x2][y2];
    if(x1-1 >= 0)   total -= sum[x1-1][y2];
    if(y1-1 >= 0)   total -= sum[x2][y1-1];
    if(x1-1 >= 0 && y1-1 >= 0)  total += sum[x1-1][y1-1];
    return total;
}

int main() {
    vector<vector<int>> matrix {{0, 2, 5, 4, 1}, {4, 8, 2, 3, 7}, {6, 3, 4, 6, 2}, {7, 3, 1, 8, 3}, {1, 5, 7, 9, 4}};

    // coordinates of required submatrix's top-left and bottom-right corners
    pair<int, int> tl = {1, 1}, br = {3, 3};

    cout << sumSubMatrix(matrix, tl, br) << endl;
    return 0;
}

/*

Preprocessing involves summing all elements dynamically from (0, 0) to (i, j).
After pre-processing matrix in O(mn) time, we can get constant time sums for any sub-matrix of any size.

Original Matrix             Preprocessed
0  2  5  4  1           0   2   7   11  12 
4  8  2  3  7           4   14  21  28  36
6  3  4  6  2   -->     10  23  34  47  57    --> sum[i][j] = matrix[i][j] + sum[i-1][j] + 
7  3  1  8  3           17  33  45  66  79                    sum[i][j-1] - sum[i-1][j-1]
1  5  7  9  4           8   39  58  88  105


Now, for sum of any sub-matrix formed by points (x1, y1), (x1, y2), (x2, y1), (x2, y2),
        y1      y2
    .   .   .   .   .
x1  .   º   º   º   .   
    .   º   º   º   .   -->  s = sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]
x2  .   º   º   º   .
    .   .   .   .   .

So, for above example, sum of sub-matrix with corners (1, 1), (1, 3), (3, 1), (3, 3),

0  2  5  4  1
4  8  2  3  7           8  2  3
6  3  4  6  2   -->     3  4  6     --> sum = 38
7  3  1  8  3           3  1  8 
1  5  7  9  4 

*/
