

link : https://leetcode.com/problems/partition-equal-subset-sum/description/
```cpp
// partition in 2 subsets , not subarrays
// exact same problem as subset sum 
// just divide sum of elements == target , then apply subset sum algo
// for that particular target . 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums)
            total += num;
        // if equal partition , then total sum is even
        if (total % 2 != 0)
            return false;
        int target = total / 2;
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= target; j++) 
            {
                if (j >= nums[i - 1]) 
                {   
                    // similar to pick || not_pick
                    //dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                    int pick = dp[i - 1][j - nums[i - 1]] ;
                    int not_pick = dp[i - 1][j] ;

                    dp[i][j] = pick || not_pick ;
                } 
                else // j < nums[i - 1] so not possible
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][target];
    }
};

```
