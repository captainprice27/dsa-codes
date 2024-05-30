// https://leetcode.com/problems/find-a-peak-element-ii/

/*A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.
Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].
You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.
You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) 
    {
        int m = mat.size(); // row 
        int n = mat[0].size();  // columns
        // traversing rows
        int low = 0;    
        int high = m - 1;

        while (low <= high) // --> O(log m)
        {
            int mid = low + (high - low) / 2;
            int peak_col = 0; //column with the peak element in a given row

        // Find the column with the maximum value in the current row (mid)
            for (int j = 0; j < n; j++) // O(n)
            {
                if (mat[mid][j] > mat[mid][peak_col]) 
                {
                    peak_col = j;
                }
            }

            // Check if the current element is a peak element
            bool isPeak = true;
            if (mid > 0 && mat[mid][peak_col] < mat[mid - 1][peak_col]) 
            {
                isPeak = false;
                high = mid - 1;  // Move to the upper half
            }
            if 
            (mid < m - 1 && mat[mid][peak_col] < mat[mid + 1][peak_col]) 
            {
                isPeak = false;
                low = mid + 1;  // Move to the lower half
            }

            if (isPeak == true) 
            {
                return {mid, peak_col};
            }
        }

        return {-1, -1};  // This line should never be reached
        // just given for the sake of that vector<int> return statement
    
    }
};

/*Explanation:
Binary Search on Rows:

Start with the middle row and find the column with the maximum value in that row.
Check if this element is a peak element by comparing it with its adjacent elements above and below.
If it's not a peak, move to the half of the matrix that contains a larger neighbor (either above or below the current row).
Peak Check:

If the element in the middle row is greater than both its neighbors (above and below), then it's a peak.
If the element is not greater than the above neighbor, move to the upper half.
If the element is not greater than the below neighbor, move to the lower half.*/
