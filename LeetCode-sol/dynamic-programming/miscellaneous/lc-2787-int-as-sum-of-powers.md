link : https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/

> The time complexity of the numberOfWays function is O(n * maxNum), where n is the input parameter and maxNum is the maximum number that can be raised to the power of x to get a number less than or equal to n. This is because there are two nested loops iterating over n and maxNum, and each iteration involves constant time operations.

>The space complexity of the function is O(n * maxNum) as well, because we are using a 2D vector of size (n+1) * (maxNum+1) to store the dynamic programming table.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfWays(int n, int x) {
        int maxNum = pow(n, 1.0 / x);
        vector<vector<int>> dp(n + 1, vector<int>(maxNum + 1, 0));

        for (int j = 0; j <= maxNum; ++j) 
        {
            dp[0][j] = 1; // Base case
        }

        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= maxNum; ++j) 
            {
                int power = pow(j, x);

                dp[i][j] = dp[i][j - 1]; // Without current number

                if (i >= power) 
                {
                    dp[i][j] = (dp[i][j] + dp[i - power][j - 1]) %
                               mod; // With current number
                }
            }
        }

        return dp[n][maxNum];
    }
};


```

### optimized with  O(n) space

>The time complexity of the numberOfWays function is O(n * sqrt(n)), where n is the input integer. This is because we iterate over all numbers from 1 to sqrt(n) and for each number, we iterate over all values from n to 1.   
>
>
>The space complexity is O(n) because we are using a vector of size n+1 to store the dynamic programming values.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case

        for (int num = 1; pow(num, x) <= n; ++num) {
            int power = pow(num, x);
            for (int i = n; i >= power; --i) {
                dp[i] = (dp[i] + dp[i - power]) % mod;
            }
        }

        return dp[n];
    }
};

```

### further spacce optimisation : 

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int numberOfWays(int n, int x) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // Base case

        for (int num = 1; pow(num, x) <= n; ++num) {
            int power = pow(num, x);
            for (int i = n; i >= power; --i) {
                dp[i] = (dp[i] + dp[i - power]) % mod;
            }
        }

        return dp[n];
    }
};


```
