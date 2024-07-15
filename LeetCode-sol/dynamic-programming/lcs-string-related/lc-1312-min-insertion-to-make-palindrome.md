link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

### space optimized approach O(m) space ...

```cpp
class Solution {
public:
    int minInsertions(string text1) 
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

        int length =  prev[m]; // length of l.c. palindromic subsequence
        // (m-length) is the #of chars which are  not part of LCPS
        // hence we can add them in opposite fashion to get Palindrome
        // and here we need insertion , hence m - length .
        int ans = m - length ;
        return ans ;
    
    }
};

```
