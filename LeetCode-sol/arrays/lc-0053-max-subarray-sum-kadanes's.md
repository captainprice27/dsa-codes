link : https://leetcode.com/problems/maximum-subarray/description/   
```cpp
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
  {
        int max_sum = INT_MIN; // maximum sum
        int curr_sum = 0;
        for (int element : nums) {

            curr_sum = max(element, element + curr_sum);
            max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
  }
};
```
