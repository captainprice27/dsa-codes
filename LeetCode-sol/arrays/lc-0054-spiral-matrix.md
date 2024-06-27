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
