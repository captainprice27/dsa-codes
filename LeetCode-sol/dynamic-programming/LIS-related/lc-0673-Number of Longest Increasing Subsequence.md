https://leetcode.com/problems/number-of-longest-increasing-subsequence/

![image](https://github.com/user-attachments/assets/71254cc4-4ca2-486a-99f6-3664444bf1f5)


```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1); // Initialize DP table
        vector<int> cnt(n, 1); // Initialize DP table

        int maxLength = 1;

        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (nums[i] > nums[j]) 
                {
                   //dp[i] = max(dp[i], dp[j] + 1);
                   if(dp[j] + 1 > dp[i]) {
                     
                    dp[i] = dp[j] + 1  ;// LIS found
                    cnt[i] = cnt[j] ;  // no change 

                   }
                   else if(dp[i] == dp[j] +1) {
                    dp[i] = dp[j] ; //
                    cnt[i] = cnt[i] + cnt[j] ;
                   }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        // return maxLength;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLength) {
                result += cnt[i];
            }
        }

        return result;
    }
};
```
