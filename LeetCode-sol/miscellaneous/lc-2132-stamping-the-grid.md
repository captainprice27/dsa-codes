link : https://leetcode.com/problems/stamping-the-grid/description/

vortubac explanation : https://leetcode.com/problems/stamping-the-grid/solutions/1676509/bag-of-tricks/

>Time complexity:
- The computePrefixSum function has a time complexity of O(rows * cols) as it iterates through each element in the matrix once.
- The getSubmatrixSum function has a time complexity of O(1) as it performs constant time operations to calculate the submatrix sum.

>Space complexity:
- The computePrefixSum function has a space complexity of O(rows * cols) as it creates a prefix sum matrix of the same size as the input matrix.
- The getSubmatrixSum function has a space complexity of O(1) as it only uses a constant amount of extra space.

>Overall, the time complexity of the possibleToStamp function depends on the time complexity of the computePrefixSum and getSubmatrixSum functions, which is O(rows * cols). The space complexity is also O(rows * cols) due to the prefix sum matrix.

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> computePrefixSum(const vector<vector<int>> &matrix, int rows, int cols) {
    vector<vector<int>> prefixSum(rows + 1, vector<int>(cols + 1, 0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            prefixSum[i + 1][j + 1] = matrix[i][j] 
                                    + prefixSum[i + 1][j] 
                                    + prefixSum[i][j + 1] 
                                    - prefixSum[i][j];
        }
    }
    return prefixSum;
}

int getSubmatrixSum(const vector<vector<int>> &prefixSum, int r1, int c1, int r2, int c2) {
    return prefixSum[r2 + 1][c2 + 1] 
         - prefixSum[r1][c2 + 1] 
         - prefixSum[r2 + 1][c1] 
         + prefixSum[r1][c1];
}

bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<int>> stampable(rows, vector<int>(cols, 0));
    
    auto gridPrefixSum = computePrefixSum(grid, rows, cols);
    
    for (int i = stampHeight - 1; i < rows; ++i) {
        for (int j = stampWidth - 1; j < cols; ++j) {
            if (getSubmatrixSum(gridPrefixSum, i - stampHeight + 1, j - stampWidth + 1, i, j) == 0) {
                stampable[i][j] = 1;
            }
        }
    }
    
    auto stampPrefixSum = computePrefixSum(stampable, rows, cols);
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0) {
                int bottomRightRow = min(i + stampHeight - 1, rows - 1);
                int bottomRightCol = min(j + stampWidth - 1, cols - 1);
                if (getSubmatrixSum(stampPrefixSum, i, j, bottomRightRow, bottomRightCol) == 0) {
                    return false;
                }
            }
        }
    }
    
    return true;
}


```
