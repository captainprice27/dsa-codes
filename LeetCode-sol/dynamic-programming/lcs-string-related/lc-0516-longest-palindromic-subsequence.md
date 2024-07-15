link : https://leetcode.com/problems/longest-palindromic-subsequence/description/

### only one string as input , you have to just take the reverse of that string , then perform the LCS operation to find LCPS 

### below is space optimized version only

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string text1) 
    {   
        string text2 = text1 ;
        reverse(text2.begin(),text2.end());

        //int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1, 0), curr(m+1, 0);

        for (int i = 1; i <= m; ++i) {
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

```
