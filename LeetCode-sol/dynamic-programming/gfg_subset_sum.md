link : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

```cpp
class Solution{   
public:
    bool isSubsetSum(vector<int>nums, int sum)
    {
        int n = nums.size();
        // dp grid is initialised  to false initially
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
        
        // when sum = 0 ; we can have an empty subset irrespective of the size of array
        for (int i = 0; i <= n; ++i) dp[i][0] = true;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= sum; j++) 
            {
                if (j >= nums[i - 1])  // pick or not_pick , bbut picking possible
                {   
                    int pick = dp[i - 1][j - nums[i - 1]] ;
                    
                    int not_pick = dp[i - 1][j] ;
                    
                    // logical OR (||) cuz if 'j' can be summed for upto 'i' indices
                    // then pick or not_pick for current element , it's TRUE .......
                    dp[i][j] = pick || not_pick ;
                } 
                else  // nums[i-1] > j then picking not possible
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};
```
