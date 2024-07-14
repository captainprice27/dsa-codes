### print any one LCS of the string : 
### note that lcs are printed in normal order , not lexicographically 
(i.e. if BDC is the lcs , it will be printedin BDC this way , not BCD)

```cpp
#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2) 
{
	
	// plain lcs code ********************************************
  int n = s1.size();
  int m = s2.size();

  vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));  

  for (int ind1 = 1; ind1 <= n; ind1++) 
  {
    for (int ind2 = 1; ind2 <= m; ind2++) 
    {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
        
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }
  
  // lcs code upto now *************************************

  int lcs_len = dp[n][m];
  int i = n;
  int j = m;

  int index = lcs_len - 1; // index of answer string i.e. lcs
  
  string str(lcs_len, '$'); // initialised with '$' dummy string
 
  
  while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) 
        {
            str[index] = s1[i - 1];
            index--;
            i--; j--;
        } 
        // if no match then check left or top elements from which dp[i][j]
        // came as max of two ...
        else if (dp[i - 1][j] > dp[i][j - 1]) 
        {
            i--;
        } 
        else  // dp[i - 1][j] < dp[i][j - 1]
        {
            j--;
        }
    }
    
  cout << str;
}



int main() {

  //string s1 = "abcde";
  //string s2 = "bdgek";
  
  string s1 ; string s2 ;  
  cin >> s1 >> s2 ;

  cout << "The LCS is: ";
  lcs(s1, s2);
}

```

another 

```cpp

#include <bits/stdc++.h>

using namespace std;

void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int len = dp[n][m];
  int i = n;
  int j = m;

  int index = len - 1;
  string str = "";
  for (int k = 1; k <= len; k++) {
    str += "$"; // dummy string
  }

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) 
    {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } 
    else if (s1[i - 1] > s2[j - 1]) {
      i--;
    } else j--;
  }
  cout << str;
}

int main() {

  //string s1 = "abcde";
  //string s2 = "bdgek";
  string s1;
  string s2;
  cin >> s1 >> s2 ;

  cout << "LCS is ";
  lcs(s1, s2);
}
```
