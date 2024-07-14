link : https://leetcode.com/problems/longest-common-subsequence/description/

### recursive --> TLE

```cpp

class Solution {
public:
    int lcsRecursive(string &text1, string &text2, int i, int j) {
        if (i == 0 || j == 0)
            return 0;
        if (text1[i-1] == text2[j-1])
            return 1 + lcsRecursive(text1, text2, i-1, j-1);
        else
            return max(lcsRecursive(text1, text2, i-1, j), lcsRecursive(text1, text2, i, j-1));
    }

    int longestCommonSubsequence(string text1, string text2) {
        return lcsRecursive(text1, text2, text1.size(), text2.size());
    }
};
```

### recursive memoization 

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcsMemoization(string &text1, string &text2, int i, int j, vector<vector<int>> &memo) {
        if (i == 0 || j == 0)
            return 0;
        if (memo[i][j] != -1)
            return memo[i][j];
        if (text1[i-1] == text2[j-1])
            memo[i][j] = 1 + lcsMemoization(text1, text2, i-1, j-1, memo);
        else
            memo[i][j] = max(lcsMemoization(text1, text2, i-1, j,memo), lcsMemoization(text1, text2, i, j-1,memo));
        return memo[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        return lcsMemoization(text1, text2, n, m, memo);
    }
};

```

### bottom-up tabulation :

```cpp
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // dp[0][0] , dp[1][0] , dp[0][1] are 0 obviously

        for (int i = 1; i <= n; i++) 
        
        {
            for (int j = 1; j <= m; j++) 
            {   
                // char matches
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                // no match 
                else
                {   int dcr_indx1 = dp[i-1][j] ;
                    int dcr_indx2 = dp[i][j-1] ; 
                    dp[i][j] = max(dcr_indx1 , dcr_indx2) ;
                    
                    // 1-liner : dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                
            }
        }
        return dp[n][m];
    }
};

```

### space optimisedd to 2 x O(n)

> The **time complexity** of this solution is **O(n*m)** , where n is the length of text1 and m is the length of text2. This is because we have a nested loop that iterates through both strings.

> The **space complexity** is **O(m)** because we are using two vectors of size m+1 to store the previous and current values of the longest common subsequence.
> INTUITION : WE NEED ONLY PREV AND CURRENT STATE OF ANY OF THE STRING SINCE SUBSEQUENCE LENGTH CAN'T BE MORE THGAN THE LENGTH OF SMALLEST STRING 
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i-1] == text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";
    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of LCS: " << result << endl;
    return 0;
}
```
