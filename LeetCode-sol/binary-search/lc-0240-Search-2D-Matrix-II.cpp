// https://leetcode.com/problems/search-a-2d-matrix-ii/
/*Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int m = mat.size(); // row size
        if (m == 0) return false;
        int n = mat[0].size();  // column size
        if (n == 0) return false;

        // Start from the top-right corner
        int row = 0;
        int col = n - 1;

        // Traverse the matrix
        while (row < m && col >= 0) 
        {
            if (mat[row][col] == target) 
            {
                return true;
            } 
            else if (mat[row][col] > target) 
            {
                col--; // Move left
            } 
            else    // mat[row][col] < target 
            {
                row++; // Move down
            }
        }

        return false; // Target not found
    }
};

/*/*Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

path -->  start point 15 , then 11 -> 7 -> 4(<5) -> 5(col++)
*/*/

/*Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

path -->  start point 15 , then 11 -> 7 -> 4(<5) -> 5(col++)
*/
