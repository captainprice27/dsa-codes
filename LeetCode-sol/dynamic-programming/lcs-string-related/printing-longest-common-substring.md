### dp table O(m*n) , not lexicographically
### just use set for  lexicographical order instead of unorderd set ...

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> longestCommonSubstrings(string s, string t) 
    {
        int n = s.size(), m = t.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        int maxLength = 0;
        
        unordered_set<string> substrings;

        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++) 
            {
                if (s[i - 1] == t[j - 1])  // MATCH
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    
                    if (dp[i][j] > maxLength) 
                    {
                        maxLength = dp[i][j]; // UPDATING MAX_LENGTH
                        substrings.clear(); // NEW LONGEST SUBSTRING POSSIBLE
                    }
                    
                    if (dp[i][j] == maxLength) 
                    {
                        substrings.insert(s.substr(i - maxLength, maxLength));
                    }
                } 
                else 
                {
                    dp[i][j] = 0;
                }
            }
        }

        vector<string> result(substrings.begin(), substrings.end());
        return result;
    }
};

int main() {
    Solution sol;
    //string s1 = "abcde";
    //string s2 = "abfce";
    
    string s1 , s2 ;
    cin >> s1 >> s2 ;
    
    vector<string> result = sol.longestCommonSubstrings(s1, s2);
    for (const string &str : result) 
    {
        cout << str << endl;
    }
    return 0;
}

```
### O(n) space optimized , not lexicographically

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> longestCommonSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        int maxLength = 0;
        unordered_set<string> substrings;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    if (curr[j] > maxLength) {
                        maxLength = curr[j];
                        substrings.clear();
                    }
                    if (curr[j] == maxLength) {
                        substrings.insert(s.substr(i - maxLength, maxLength));
                    }
                } else {
                    curr[j] = 0;
                }
            }
            swap(prev, curr);
            fill(curr.begin(), curr.end(), 0);
        }

        vector<string> result(substrings.begin(), substrings.end());
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "abcde";
    string s2 = "abfce";
    vector<string> result = sol.longestCommonSubstrings(s1, s2);
    for (const string &str : result) {
        cout << str << endl;
    }
    return 0;
}

```

### lexocographiical order

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> longestCommonSubstrings(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int maxLength = 0;
        set<string> substrings;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        substrings.clear();
                    }
                    if (dp[i][j] == maxLength) {
                        substrings.insert(s.substr(i - maxLength, maxLength));
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        vector<string> result(substrings.begin(), substrings.end());
        return result;
    }
};

int main() {
    Solution sol;
    string s1 = "abcde";
    string s2 = "abfce";
    vector<string> result = sol.longestCommonSubstrings(s1, s2);
    for (const string &str : result) {
        cout << str << endl;
    }
    return 0;
}


```
