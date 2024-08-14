

link : https://leetcode.com/problems/find-the-median-of-the-uniqueness-array/description/

>The time complexity of this solution is O(n) because we are iterating through the array once.
>The space complexity is O(n) because we are using an unordered_map to store the frequency of elements in the array.
>
>### explanation :
>
Explanation:
Binary Search Range:

We are searching for the smallest uniqueness value left such that at least medianPosition subarrays have a number of distinct elements less than or equal to left.
Sliding Window for Counting:

The sliding window approach uses a frequency map to keep track of distinct elements. If the number of distinct elements exceeds the current mid, we move the left pointer of the window to the right until the number of distinct elements is valid again.
Binary Search Logic:

If the count of subarrays with distinct elements less than or equal to mid is greater than or equal to medianPosition, we narrow our search to smaller values by setting right = mid.
Otherwise, we search for larger values by setting left = mid + 1.
Final Result:

The binary search converges on the smallest uniqueness value that is the median of all possible subarray uniqueness values.
```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int medianOfUniquenessArray(vector<int>& nums) 
    {
        long long n = nums.size();
        
        // Helper function to count subarrays with distinct elements <= maxDistinct
        auto countSubarraysWithDistinct = [&](long long maxDistinct) {
            unordered_map<long long, long long> freq;
            long long left = 0, count = 0, distinctCount = 0;
            
            for (long long right = 0; right < n; ++right) {
                if (++freq[nums[right]] == 1) {
                    ++distinctCount;
                }
                
                while (distinctCount > maxDistinct) {
                    if (--freq[nums[left]] == 0) {
                        --distinctCount;
                    }
                    ++left;
                }
                
                // Add the number of subarrays ending at right
                count += right - left + 1;
            }
            
            return count;
        };
        
        // Binary search over possible distinct counts
        long long left = 1, right = n;
        long long totalSubarrays = n * (n + 1) / 2;
        long long medianPosition = (totalSubarrays + 1) / 2;
        
        while (left < right) 
        {
            long long mid = left + (right - left) / 2;
            long long subarrayCount = countSubarraysWithDistinct(mid);
            
            if (subarrayCount >= medianPosition) 
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
