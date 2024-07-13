link : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

```cpp
const int MOD = 1e9 + 7;

class Solution {
public:
    int perfectSum(int arr[], int n, int sum) {
        int dp[1001][1001] = {0};

        for (int i = 0; i <= n; ++i) dp[i][0] = 1; 
        // Sum 0 can always be achieved by the empty subset ,  hence true/1

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 0; j <= sum; j++) 
            {
                dp[i][j] = dp[i - 1][j] % MOD;
                
                if (j >= arr[i - 1]) 
                {
                    // || --> + to count all the subsets
                    // || --> is used to OR true/false values
                    int pick_ith = dp[i - 1][j - arr[i - 1]] % MOD ;
                    
                    int not_pick_ith = dp[i-1][j] % MOD;
                    
                    dp[i][j] = (pick_ith + not_pick_ith) % MOD;
                }
            }
        }

        return dp[n][sum];
    }
};

```

### space optimized dp

```cpp
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
    int perfectSum(int arr[], int n, int sum) {
        int dp[1001] = {0};
        dp[0] = 1; // Sum 0 can always be achieved by the empty subset

        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= arr[i]; --j) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }

        return dp[sum];
    }
};
```
