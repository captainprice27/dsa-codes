link : https://leetcode.com/problems/wildcard-matching/

### recursive (gpt) starts from base to target ... ulta process like tabulation type

```cpp

class Solution {
public:
    bool isMatch(string s, string p)
     { 
        return helper_pm(s, p, 0, 0); 
    }

    bool helper_pm(const string& s, const string& p, int i, int j) 
    {
        if (j == p.size())
            return i == s.size();
        if (i < s.size() && (s[i] == p[j] || p[j] == '?')) 
        {
            return helper_pm(s, p, i + 1, j + 1);
        }
        if (p[j] == '*') 
        {
            return helper_pm(s, p, i, j + 1) ||
                   (i < s.size() && helper_pm(s, p, i + 1, j));
        }
        return false;
    }
};
```

### normal recursive 915/1612 t.c. passed

```cpp
class Solution {
public:
    bool isMatch(string s, string p)
     { 
        //return helper_pm(s, p, 0, 0); 
        int n = s.size();
        int m = p.size();
        return helper_pm(s,p,n-1,m-1);
    }

    bool helper_pm(const string& s, const string& p, int i, int j) 
    {
        // if (j == p.size())
            // return i == s.size();
        // if (i < s.size() && (s[i] == p[j] || p[j] == '?')) 
        // {
            // return helper_pm(s, p, i + 1, j + 1);
        // }
        // if (p[j] == '*') 
        // {
            // return helper_pm(s, p, i, j + 1) ||
                   // (i < s.size() && helper_pm(s, p, i + 1, j));
        // }
        // return false;
        
        
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false ;
        
        if(j < 0 && i>= 0)
        {
        	for(int pt =0;pt<=i;pt++)
        	{
        		if(p[pt] != '*') return false;
        	}
        	return true ;
        }
        
        if((s[i] == p[j] || p[j] == '?'))
        	return helper_pm(s,p,i-1,j-1);
        
        if(p[j] == '*')
        	return helper_pm(s,p,i-1,j) || helper_pm(s,p,i,j-1);
        
        return false ;     
        
        
    }
};

```


### tabulation approach ******************
```cpp

class Solution {
public:
    bool isMatch(string s, string p)
    {
        int n = s.size(), m = p.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        dp[0][0] = true;
        
        // below  is checking whether empty strings are matched
        // with * sequence , when s.size() = 0 . 
        for (int j = 1; j <= m; ++j) 
        {
            if (p[j - 1] == '*') 
            {
                dp[0][j] = dp[0][j - 1];
                // dp[0][j] = true; // --> 1420/1811 passed in this
            }            
        }
        
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= m; ++j) 
            {
                if (p[j - 1] == '*') 
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } 
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) 
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[n][m];
    }
};
```

### space optimization : 

```cpp

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        vector<bool> prev(m + 1, false), curr(m + 1, false);

        prev[0] = true;
        
        for (int j = 1; j <= m; ++j) 
        {
            if (p[j - 1] == '*') 
            {
                prev[j] = prev[j - 1];
            }
        }
        
        for (int i = 1; i <= n; ++i) 
        {
            curr[0] = false;
            for (int j = 1; j <= m; ++j) 
            {
                if (p[j - 1] == '*') 
                {
                    curr[j] = curr[j - 1] || prev[j];
                } 
                else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) 
                {
                    curr[j] = prev[j - 1];
                } 
                else // char no match then false
                {
                    curr[j] = false;
                }
            }
            //swap(prev, curr);
            prev = curr ;
        }
        
        return prev[m];
    }
};
```
