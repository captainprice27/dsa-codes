// link : https://leetcode.com/problems/perfect-squares/description/

> The time complexity of this solution is O(n * sqrt(n)), where n is the input number. This is because we have a nested loop where the outer loop runs from 1 to n and the inner loop runs from 1 to sqrt(n). 

> The space complexity is O(n) because we are using a vector of size n+1 to store the dynamic programming values.

```cpp
class Solution {
public:
    int numSquares(int n) 
    {
        if(n <= 0) return 0; // base case on 'n'
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0; // base case, 0 sum is made by one way only

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) 
            {   
                // this line is imp for signed int overflow problem
                if (dp[i - j * j] != INT_MAX) 
                {
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }

        return dp[n];
    }
};


```
