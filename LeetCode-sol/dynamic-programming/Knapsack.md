cp algo : https://cp-algorithms.com/dynamic_programming/knapsack.html

0-1 knapsack recursive : 

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
        // Base case: No items left or no capacity left
        if (n == 0 || W == 0) return 0;

        // If the weight of the nth item is more than the capacity
        if (weights[n-1] > W)
        {
            return knapsack(W, weights, values, n-1);
        }
    
        else
          {
            // Return the maximum of two cases: pick or not pick
            int pick = values[n-1] + knapsack(W - weights[n-1], weights, values, n-1);
            int not_pick = knapsack(W, weights, values, n-1);
            return max(pick , not_pick);            
                
          }
    }
};

```

### memoization : exact similar to recursive but with memory

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& weights, vector<int>& values, int n, vector<vector<int>>& memo) {
        // Base case: No items left or no capacity left
        if (n == 0 || W == 0) return 0;

        // Check if value already computed
        if (memo[n][W] != -1) return memo[n][W];

        // If the weight of the nth item is more than the capacity
        if (weights[n-1] > W)
        {
            memo[n][W] = knapsack(W, weights, values, n-1, memo);
        }
        else
        {
            // Return the maximum of two cases: pick or not_pick            
            int pick = values[n-1] + knapsack(W - weights[n-1], weights, values, n-1, memo);
            int not_pick = knapsack(W, weights, values, n-1, memo) ;
            memo[n][W] = max( pick , not_pick);
        }
        return memo[n][W];
    }
};

```

### bottom-up / tabulation 

```cpp
// w --> variable maximum capacity of knapsack
// W --> a particular value of 'w' , and also the largest .. i.e. (1<= w <= W)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) 
            {
                if (weights[i-1] <= w) 
                {   // pick or not pick
                    int pick = values[i-1] + dp[i-1][w - weights[i-1]];
                    int not_pick = dp[i-1][w] ;
                    dp[i][w] = max(pick,not_pick);
                } 
                else 
                {   // weights[i-1] > w , then not possible to include
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        // since we want ans of array of size 'n' ansd max capacity 'W'
        return dp[n][W];
    }
};

```

### space-optimized bottom-up with O(n) space 

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<int> dp(W+1, 0);

        for (int i = 0; i < n; ++i) {
            for (int w = W; w >= weights[i]; --w) {
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }
        return dp[W];
    }
};
```
