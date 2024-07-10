link : https://leetcode.com/problems/triangle/description/

### recursive(TLE)

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return helper(triangle, 0, 0);
    }

private:
    int helper(vector<vector<int>>& triangle, int row, int col) {
        if (row == triangle.size()) return 0;
        int left = helper(triangle, row + 1, col);
        int right = helper(triangle, row + 1, col + 1);
        return triangle[row][col] + min(left, right);
    }
};

```

### tabulation : 

```cpp

// here , bottom would be largest row and up would be dp[0][0]
// since the array is like :
/*    * --> dp[0][0]
     ***
    *****
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size(); // n --> # of rows
        vector<vector<int>> dp = triangle;

        //row will start from (n-2) , not (n-1)

        for (int row = n - 2; row >= 0; row--) 
        {
            for (int col = 0; col <= row; col++) 
            {
                dp[row][col] += min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }
        return dp[0][0];
    }
};

```

### Space optimization : 

```cpp

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1]; // Start with the last row

        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col <= row; ++col) {
                dp[col] = triangle[row][col] + min(dp[col], dp[col + 1]);
            }
        }
        return dp[0];
    }
};

```
