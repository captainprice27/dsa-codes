link : https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
> The time complexity of this solution is O(m * log(m*n)), where m is the number of rows and n is the number of columns. This is because we are performing a binary search on the range of numbers from 1 to m*n, and for each mid value, we are counting the number of elements less than or equal to mid in O(m) time.

> The space complexity is O(1) as we are not using any extra space that grows with the input size.
>
> ### explanation :
>
> Explanation:
>Binary Search Range: We start with the range from 1 to m * n because the smallest element is 1 and the largest element is m * n.

>Counting Elements: For each potential middle value mid, we count how many elements in the table are less than or equal to mid. This is done by iterating through each row i and summing min(mid // i, n) for all rows.

>Binary Search Adjustment: If the count of elements less than or equal to mid is at least k, it means mid might be our answer, so we search in the left half by setting right = mid. Otherwise, we search in the right half by setting left = mid + 1.

>Final Result: When the binary search completes, left will be the kth smallest element in the multiplication table.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int findKthNumber(int m, int n, int k) 
    {
        int left = 1, right = m * n;
        
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            
            // Count the number of elements <= mid
            int count = 0;
            for (int i = 1; i <= m; i++) 
            {
                count += min(mid / i, n);
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
