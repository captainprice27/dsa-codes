link : https://leetcode.com/problems/spiral-matrix/description/

```cpp
#include <vector>
#include <algorithm> // for reverse

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        while (!matrix.empty()) {
            // Take the first row
            result.insert(result.end(), matrix[0].begin(), matrix[0].end());
            matrix.erase(matrix.begin());
            if (!matrix.empty()) {
                // Rotate the matrix counterclockwise
                matrix = rotateMatrix(matrix);
            }
        }
        return result;
    }
    
private:
    vector<vector<int>> rotateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> rotatedMatrix;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int col = cols - 1; col >= 0; --col) {
            vector<int> newRow;
            for (int row = 0; row < rows; ++row) {
                newRow.push_back(matrix[row][col]);
            }
            rotatedMatrix.push_back(newRow);
        }
        return rotatedMatrix;
    }
};

```

### striver approach 

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // m --> # columns , n --> # rows
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;
        while (top <= bottom && left <= right) 
        {
            // For moving left to right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            // updating top ; 
            top++;

            // For moving top to bottom.
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);

            right--;

            // For moving right to left.
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);

                bottom--;
            }

            // For moving bottom to top.
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);

                left++;
            }
        }

        return ans ; 
    }
};
```
