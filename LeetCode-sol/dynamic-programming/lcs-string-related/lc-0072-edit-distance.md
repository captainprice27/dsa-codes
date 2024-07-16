link : https://leetcode.com/problems/edit-distance/description/

### recursive sol .. TLE

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) 
    {   
        int n = word1.size();
        int m = word2.size();
        return helper(word1, word2, n, m);
    }

    int helper(string& word1, string& word2, int i, int j) 
    {
        if (i == 0) return j;
        if (j == 0) return i;

        // here word1 and word2 --> 0-based indexing , so highest n-1 and m-1

        if (word1[i - 1] == word2[j - 1])
            return helper(word1, word2, i - 1, j - 1);
        
        return 1 + min({helper(word1, word2, i - 1, j),  // delete
                        helper(word1, word2, i, j - 1),  // insert
                        helper(word1, word2, i - 1, j - 1)}); // replace
    }
};

```

### memoization from recursive 

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) 
    {   int n = word1.size();
        int m = word2.size() ;
        vector<vector<int>> memo(n + 1,
                                 vector<int>(m + 1, -1));
        return helper(word1, word2 , n , m , memo);
    }


    int helper(string& word1, string& word2, int i, 
                int j,vector<vector<int>>& memo) 
    {
        if (i == 0) return j;

        if (j == 0) return i;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (word1[i - 1] == word2[j - 1])
            return memo[i][j] = helper(word1, word2, i - 1, j - 1, memo);

        return memo[i][j] =  1 +
                   min({helper(word1, word2, i - 1, j, memo),       // delete
                        helper(word1, word2, i, j - 1, memo),       // insert
                        helper(word1, word2, i - 1, j - 1, memo)}); // replace
    }
};


```

### tabulation 
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i <= m; ++i) 
        {
            for (int j = 0; j <= n; ++j) 
            {
                if (i == 0) 
                {
                    dp[i][j] = j;
                } 
                else if (j == 0) 
                {
                    dp[i][j] = i;
                } 
                else if (word1[i - 1] == word2[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                else 
                {
                    dp[i][j] = 1 + min({dp[i - 1][j],  // delete
                                        dp[i][j - 1],  // insert
                                        dp[i - 1][j - 1]}); // replace
                }
            }
        }
        
        return dp[m][n];
    }
};
```

### space optimized sol
```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        
        for (int j = 0; j <= n; ++j) 
        {
            prev[j] = j;
        }
        
        for (int i = 1; i <= m; ++i) 
        {
            curr[0] = i;
            for (int j = 1; j <= n; ++j) 
            {
                if (word1[i - 1] == word2[j - 1]) 
                {
                    curr[j] = prev[j - 1];
                } 
                else 
                {
                    curr[j] = 1 + min({prev[j],  // delete
                                       curr[j - 1],  // insert
                                       prev[j - 1]}); // replace
                }
            }
            //prev.swap(curr);
            prev = curr ;
        }
        
        return prev[n];
    }
};
```
