https://leetcode.com/problems/split-array-largest-sum/


```cpp
class Solution {
public:
    int countPartitions(vector<int>& a, int maxSum) 
    {
        int n = a.size(); // size of array.
        int partitions = 1;
        long long subarraySum = 0;

        for (int i = 0; i < n; i++) 
        {
            if (subarraySum + a[i] <= maxSum) 
            {
                // insert element to current subarray
                subarraySum += a[i];
            } 
            else 
            {
                // insert element to next subarray
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& nums , int k) 
    {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        // Apply binary search:
        while (low <= high) 
        {
            int mid = low + (high - low) / 2;

            int partitions = countPartitions(nums, mid);
            
            if (partitions > k) 
            {
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }
        return low;
    }
};
```
**The time complexity of the provided solution can be analyzed as follows:**

1. The `countPartitions` function iterates through the array `a` of size `n`, performing a linear scan to count the number of partitions based on the given `maxSum`. This results in a time complexity of O(n) for each call to `countPartitions`.

2. The `splitArray` function employs a binary search over the range from `low` to `high`. The range is determined by the maximum element in the array (O(n) to find) and the sum of all elements (O(n) to compute). The binary search itself runs in O(log(sum)), where `sum` is the total of the elements in the array.

3. Since `countPartitions` is called within the binary search, the overall time complexity of the `splitArray` function becomes O(n * log(sum)), where `n` is the number of elements in the array and `sum` is the total sum of the elements.

In terms of space complexity:

1. The space complexity is O(1) for the `countPartitions` function, as it uses a constant amount of extra space regardless of the input size.

2. The `splitArray` function also uses a constant amount of extra space, leading to an overall space complexity of O(1).

In summary, the time complexity of the solution is O(n * log(sum)), and the space complexity is O(1).
