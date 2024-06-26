link : https://leetcode.com/problems/binary-subarrays-with-sum/description/

```cpp
class Solution {
public:
    int less_equal_to_goal(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int left = 0,right = 0,ans = 0,n = nums.size(),sum = 0;
        while (right < n) 
        {
            sum += nums[right];

            while (sum > goal) 
            {
                sum -= nums[left];
                left++;
            }
            ans += (right - left + 1);
            right++;
        }
        return ans;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return less_equal_to_goal(nums, goal) -
               less_equal_to_goal(nums, goal - 1);
    }
};
```
