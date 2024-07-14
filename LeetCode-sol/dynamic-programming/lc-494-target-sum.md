### chatGPT tabulaton :

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        if (target > totalSum || target < -totalSum) {
            return 0;
        }
        
        int offset = totalSum;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * totalSum + 1, 0));
        dp[0][offset] = 1;
        
        for (int i = 1; i <= nums.size(); i++) {
            for (int sum = -totalSum; sum <= totalSum; sum++) {
                if (dp[i - 1][sum + offset] > 0) {
                    dp[i][sum + nums[i - 1] + offset] += dp[i - 1][sum + offset];
                    dp[i][sum - nums[i - 1] + offset] += dp[i - 1][sum + offset];
                }
            }
        }
        
        return dp[nums.size()][target + offset];
    }
};

```
