link : https://leetcode.com/problems/01-matrix/description/

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all 0 cells
        // for a 0 cell , nearest 0-dist == 0 
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (mat[i][j] == 0) 
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions array for moving in 4 possible directions
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // BFS traversal
        while (!q.empty()) 
        {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) 
            {   
                // nr --> neighbour row , dr --> del_row 
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) 
                {
                    if (dist[nr][nc] > dist[r][c] + 1) 
                    {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return dist;
    }
};

```
