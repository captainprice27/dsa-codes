link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/


>The time complexity of this solution is O(n*log(max-min)), where n is the size of the matrix and max-min is the difference between the maximum and minimum elements in the matrix. This is because we are performing a binary search on the range of values in the matrix.

>The space complexity is O(1) because we are not using any extra space that scales with the input size, only a few variables for storing indices and counts.

```cpp

class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n-1][n-1];
        
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            int count = 0, j = n - 1;
            
            // Count how many numbers are <= mid
            for (int i = 0; i < n; i++) 
            {
                while (j >= 0 && matrix[i][j] > mid) 
                {
                    j--;
                }
                count += (j + 1);
            }
            
            if (count >= k) 
            {
                right = mid;
            } 
            else 
            {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

```
