
### tabulation O(m*n) space

```cpp

// O(n*m) space
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubstring(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int maxLength = 0;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                if (s[i-1] == t[j-1])  // MATCH
                {
                    dp[i][j] = 1 + dp[i-1][j-1]; // diagonally
                    maxLength = max(maxLength, dp[i][j]);
                } 
                
                else // NOT MATCH
                {
                    dp[i][j] = 0; // NO CHANGE
                }
            }
        }
        return maxLength;
    }
};

int main() {
    Solution sol;
    //string s1 = "abcde";
    //string s2 = "abfce";
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    cout << sol.longestCommonSubstring(s1, s2) << endl;
    return 0;
}
```

### space optimized version .. O(m) + O(m) space

```cpp

// SPACE OPTIMIZED VERSION
class Solution{
    public:
    
    int longestCommonSubstr (string s, string t, int n, int m)
    {
        
        //int n = s.size(), m = t.size(); --> if only strings  are given
        vector<int> prev(m+1, 0), curr(m+1, 0);
        int maxLength = 0;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                if (s[i-1] == t[j-1]) // MATCH
                {
                    curr[j] = 1 + prev[j-1];
                    maxLength = max(maxLength, curr[j]);
                } 
                else  // NOT MATCH
                {
                    curr[j] = 0;
                }
            }
            prev = curr ;
            //swap(prev, curr);  --> this will work too
        }
        return maxLength;
    }
};

```
