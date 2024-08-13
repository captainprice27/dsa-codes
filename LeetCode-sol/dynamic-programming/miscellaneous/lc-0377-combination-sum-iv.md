link : https://leetcode.com/problems/combination-sum-iv/description/

> The time complexity of this solution is O(target * n), where n is the number of elements in the nums array and target is the target sum. This is because we iterate through each number from 1 to target and for each number, we iterate through each element in the nums array.

>  The space complexity is O(target) because we are using a vector of size target + 1 to store the dynamic programming array dp.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
  {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i)
      {
            for (int num : nums)
            {
                if (i >= num)
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};

```
