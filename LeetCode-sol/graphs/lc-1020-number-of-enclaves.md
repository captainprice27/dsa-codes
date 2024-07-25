### similar to flood fill algo ...
```cpp

// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// BFS

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        // Enqueue all boundary land cells
        for (int i = 0; i < m; ++i) 
        {
            if (grid[i][0] == 1) q.push({i, 0});
            if (grid[i][n-1] == 1) q.push({i, n-1});
        }

        for (int j = 0; j < n; ++j) 
        {
            if (grid[0][j] == 1) q.push({0, j});
            if (grid[m-1][j] == 1) q.push({m-1, j});
        }

        // Mark all reachable land cells
        while (!q.empty()) 
        {
            auto [i, j] = q.front();
            q.pop();
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
                continue ;

            grid[i][j] = 0; // Mark as visited
            q.push({i+1, j});
            q.push({i-1, j});
            q.push({i, j+1});
            q.push({i, j-1});
        }

        // Count the remaining land cells
        int count = 0;
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (grid[i][j] == 1) count++;
            }
        }

        return count;
    }
};
```
