// link : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=partitions-with-given-difference


### problem takes inspiration from Perfect sum problem ... infact slight twist only ...
```cpp
const int MOD = 1e9 + 7;

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;

        // Calculate the total sum of the array
        for (int elem :arr) 
        {
            totalSum += elem;
        }

        // Check if (totalSum + d) is an even number and d is non-negative
        if ((totalSum + d) % 2 != 0 || d > totalSum) 
        {
            return 0;
        }

        int target = (totalSum + d) / 2;

        // Initialize a DP table to store the results of the subset sum problem
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        // Base case: If no elements are selected (sum is 0), it's a valid subset
        for (int i = 0; i <= n; i++) 
        {
            dp[i][0] = 1;
        }

        // Fill in the DP table using a bottom-up approach
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 0; j <= target; j++) 
            {
                dp[i][j] = dp[i - 1][j] % MOD;
                
                if (arr[i - 1] <= j) 
                {	
                	int pick = dp[i - 1][j - arr[i - 1]] ;
                	int not_pick = dp[i][j] ;
                	
                    dp[i][j] = (pick + not_pick) % MOD;
                }
            }
        }

        return dp[n][target];
    }
};

```
