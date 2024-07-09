link : https://leetcode.com/problems/unique-paths-ii/description/

### recursive : (TLE)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return helper(grid, m - 1, n - 1);
    }

private:
    int helper(vector<vector<int>>& grid, int m, int n) {
        if (m < 0 || n < 0 || grid[m][n] == 1) return 0; // Out of bounds or obstacle
        if (m == 0 && n == 0) return 1; // Start point
        return helper(grid, m - 1, n) + helper(grid, m, n - 1);
    }
};

```

### memoization (top down approach)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return helper(grid, m - 1, n - 1, memo);
    }

private:
    int helper(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& memo) {
        if (m < 0 || n < 0 || grid[m][n] == 1) return 0; // Out of bounds or obstacle
        if (m == 0 && n == 0) return 1; // Start point
        if (memo[m][n] != -1) return memo[m][n];
        memo[m][n] = helper(grid, m - 1, n, memo) + helper(grid, m, n - 1, memo);
        return memo[m][n];
    }
};

```

### bottom-up(tabulation) 

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1)
            return 0; // Start point is an obstacle

        vector<vector<int>> dp(m, vector<int>(n, 0));
        // all are initialised to zero ...
        dp[0][0] = 1;
        // for loops are started from '0' because obstacle can be 
        // in [0][1] or [1][0] also ...

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (grid[i][j] == 1) {
                    dp[i][j] = 0; // Obstacle
                } 
                else 
                {
                    if (i >= 1) // >= to satisfy the (i-1) condition
                        dp[i][j] += dp[i - 1][j];
                    if (j >= 1)
                        dp[i][j] += dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
```

### space optimization (advanced)

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1) return 0; // Start point is an obstacle

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dp[j] = 0; // Obstacle
                }
                else if (j > 0)
                {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[n - 1];
    }
};

```
