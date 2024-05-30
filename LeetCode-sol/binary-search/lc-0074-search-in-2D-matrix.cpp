/*You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.*/

/*# Intuition

You can think this problem as a combo of two binary search problems . One for row and another for column . Brute force may take a time complexity of about **O(m*n)** . Here we are finding the correct row first and then we will be moving towards finding the correct column , all through Binary Search . 
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) 
    {
        int m = mat.size(); // row size
        if (m == 0) return false;
        int n = mat[0].size();  // column size
        if (n == 0) return false;
        // so total m*n sized array

        int low = 0;
        int high = m - 1;

        // Finding the correct row through BS
        // column is fixed .. here say it is 0 , i.e first column
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;

            if (mat[mid][0] == target) 
            {
                return true;
            } 
            else if (mat[mid][0] < target) 
            {
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }
        // now we have got the right row after BS on row
        int row = high;
        if (row < 0) return false;

        // setting up low and high for another BS 
        // but this time its for column
        low = 0;
        high = n - 1;

        // Finding the target in the identified row
        // row is fixed as 'row' , column changes from 0 to (n-1)
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            
            if (mat[row][mid] == target) 
            {
                return true;
            } 
            else if (mat[row][mid] < target) 
            {
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }

        return false;
    }
};


/*# Complexity
- Time complexity:

**O((log n) + (log m))** == O(log (m*n))
Explanation : O(log m) for finding the correct row
Then O(log n) for finding the correct column . 
It is not O(log m * log n) since there is no nesting loop .*/
