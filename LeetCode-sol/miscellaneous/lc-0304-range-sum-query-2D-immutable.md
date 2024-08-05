
link : https://leetcode.com/problems/range-sum-query-2d-immutable/description/

another one with better spce complexity : https://leetcode.com/problems/range-sum-query-2d-immutable/solutions/75350/clean-c-solution-and-explaination-o-mn-space-with-o-1-time/

>The time complexity of the constructor is O(m*n), where m is the number of rows and n is the number of columns in the input matrix. This is because we iterate through each cell of the prefixSum matrix once to calculate the prefix sums.

>The space complexity of the constructor is also O(m*n) because we create a prefixSum matrix of the same dimensions as the input matrix.

>The time complexity of the sumRegion function is O(1) because we are able to calculate the sum of the submatrix in constant time using the prefix sums.

>The space complexity of the sumRegion function is O(1) because we are not using any additional space to calculate the sum of the submatrix.
>
```cpp

#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> prefixSum;

    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Initialize prefixSum matrix with the same dimensions as the input matrix
        prefixSum = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        
        // Fill the prefixSum matrix
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefixSum[i][j] = matrix[i-1][j-1] 
                                  + prefixSum[i-1][j] 
                                  + prefixSum[i][j-1] 
                                  - prefixSum[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Convert to 1-based indexing for the prefixSum matrix
        row1++;
        col1++;
        row2++;
        col2++;
        
        return prefixSum[row2][col2]
             - prefixSum[row1-1][col2]
             - prefixSum[row2][col1-1]
             + prefixSum[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

```
