link : https://leetcode.com/problems/longest-increasing-subsequence/description/

![image](https://github.com/user-attachments/assets/24cb0d99-9712-49d3-8525-5dd179bc8416)


```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1); // Initialize DP table
        int maxLength = 1;

        for (int i = 1; i < n; i++) 
        {
            for (int j = 0; j < i; j++) 
            {
                if (nums[i] > nums[j]) 
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
```
