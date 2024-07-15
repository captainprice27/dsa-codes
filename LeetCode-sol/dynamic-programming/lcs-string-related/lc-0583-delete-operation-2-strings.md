link : https://leetcode.com/problems/delete-operation-for-two-strings/

### space optimized version O(m) , for normal tabulation , copy paste LCS code and we are good to  go ...
```cpp
// EXACT LCS CODE ************************************************************
// just tale the LCS of two strings ...
// then length of that string - len_lcs is #of chars have to delete for one string
// for two , total len(string1)+len(string2) - 2*lcs_length
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size(); 
        
        vector<int> prev(m+1, 0), curr(m+1, 0);

        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= m; ++j) 
            {
                if (word1[i-1] == word2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        int lcs_len =  prev[m];
        return m+n - 2*lcs_len ; 
    }
};
```
