https://leetcode.com/problems/delete-greatest-value-in-each-row/description/



```cpp
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Sort each row so that greatest values are at the end
        for (int i = 0; i < m; ++i) {
            sort(grid[i].begin(), grid[i].end());
        }

        int ans = 0;
        
        // Loop over columns from right to left (greatest to smallest)
        for (int col = n - 1; col >= 0; col--) {
            // for each column dcr , we have only one elem to choose
            // which is maxval = max(all the elem in that col)
            int maxVal = 0;

            for (int row = 0; row < m; row++) {
                maxVal = max(maxVal, grid[row][col]);
            }
            ans += maxVal;
        }
        
        return ans;
    }
};

```
