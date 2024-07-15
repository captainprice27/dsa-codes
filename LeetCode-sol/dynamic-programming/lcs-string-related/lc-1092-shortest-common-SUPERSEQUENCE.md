link : https://leetcode.com/problems/shortest-common-supersequence/description/

### tabulation method , space optimized is also easy ... O(m*n) space

>The time complexity of this solution is O(n*m), where n is the length of string s1 and m is the length of string s2. This is because we are using a dynamic programming approach to find the longest common subsequence between the two strings, which requires iterating through both strings and filling up a 2D dp array.

>The space complexity of this solution is also O(n*m) because we are using a 2D dp array of size (n+1) x (m+1) to store the lengths of the longest common subsequences for all possible prefixes of the two strings.

```cpp

class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] =
                        0 + max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
		
		// upto this LCS code ***************************************
        int len = dp[n][m];
        int i = n;
        int j = m;

        int index = len - 1; // index of ans string i.e. super_seq.
        string ans = "";

        while (i > 0 && j > 0) 
        {
            if (s1[i - 1] == s2[j - 1])  // match
            {
                ans += s1[i - 1];  // include any one of it
                index--;
                i--;
                j--;
            } 
            
            // means upwords
            else if (dp[i - 1][j] > dp[i][j - 1]) 
            {
                ans += s1[i - 1];
                i--;
            } 
            else // sideways 
            {
                ans += s2[j - 1];
                j--;
            }
        }

        // Adding Remaing Characters - Only one of the below two while loops will run

        while (i > 0) {
            ans += s1[i - 1];
            i--;
        }
        while (j > 0) {
            ans += s2[j - 1];
            j--;
        }
		
		// WE NEED TO REVERSE SINCE WE ADDED IN REVERSE ORDER
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

```
