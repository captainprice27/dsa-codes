link : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

## 1-indexed recursion : 
```cpp

class Solution {
public:
    int cutRodUtil(vector<int>& price, int n) {
        if (n <= 0) return 0;

        int max_val = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int val = price[i - 1] + cutRodUtil(price, n - i);
            max_val = max(max_val, val);
        }
        return max_val;
    }

    int cutRod(vector<int>& price, int n) {
        return cutRodUtil(price, n);
    }
};

```

## 1-indexed recursive memo

```cpp
class Solution {
public:
    int cutRodUtil(vector<int>& price, int n, vector<int>& dp) {
        if (n <= 0) return 0;
        if (dp[n] != -1) return dp[n];

        int max_val = INT_MIN;
        for (int i = 1; i <= n; i++) {
            int val = price[i - 1] + cutRodUtil(price, n - i, dp);
            max_val = max(max_val, val);
        }
        return dp[n] = max_val;
    }

    int cutRod(vector<int>& price, int n) {
        vector<int> dp(n + 1, -1);
        return cutRodUtil(price, n, dp);
    }
};

```

### 1-indexed tabulation : 

```cpp
class Solution {
public:
    int cutRod(vector<int>& price, int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int max_val = INT_MIN;
            for (int j = 1; j <= i; j++) {
                max_val = max(max_val, price[j - 1] + dp[i - j]);
            }
            dp[i] = max_val;
        }
        return dp[n];
    }
};

```

## most imp --> space optimised to remove xtra var.

```cpp

class Solution {
public:
    int cutRod(vector<int>& price, int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        return dp[n];
    }
};

```

## space optimised 0-indexing 

```cpp
class Solution {
public:
    int cutRod(vector<int>& price, int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] = max(dp[i], price[j] + dp[i - (j + 1)]);
            }
        }
        return dp[n];
    }
};

```
