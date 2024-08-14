link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/

discussion link : https://leetcode.com/problems/find-k-th-smallest-pair-distance/solutions/109082/approach-the-problem-using-the-trial-and-error-algorithm/?envType=daily-question&envId=2024-08-14

>The time complexity of this solution is O(n log n + n log(max-min)), where n is the number of elements in the input array and max-min is the difference between the maximum and minimum elements in the array. The O(n log n) term comes from sorting the input array, and the O(n log(max-min)) term comes from the binary search process. 

>The space complexity is O(1) because the algorithm only uses a constant amount of extra space regardless of the input size.

```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Binary search for the answer
        int left = 0, right = nums[n - 1] - nums[0];
        while (left < right) 
        {
            int mid = left + (right - left) / 2;

            // Count pairs with distance <= mid
            int count = 0;
            int j = 0;
            for (int i = 0; i < n; i++) 
            {
                while (j < n && nums[j] - nums[i] <= mid) 
                {
                    j++;
                }
                count += j - i - 1; 
                // (j - i - 1) is the number of valid pairs
                // with i as the first element
            }

            if (count >= k) 
            {
                right = mid; // Try to find a smaller or equal distance
            } 
            else 
            {
                left = mid + 1; // Look for a larger distance
            }
        }

        return left;
    }
};


```
