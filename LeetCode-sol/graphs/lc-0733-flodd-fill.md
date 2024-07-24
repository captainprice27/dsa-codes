link : https://leetcode.com/problems/flood-fill/

### BFS solution ...

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
  {
        int originalColor = image[sr][sc];
        if (originalColor == newColor) return image;

        int rows = image.size();

        int cols = image[0].size();

        queue<pair<int, int>> q;

        q.push({sr, sc});

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            image[x][y] = newColor;

            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto [dx, dy] : directions)
            {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && image[nx][ny] == originalColor)
                {
                    q.push({nx, ny});
                }
            }
        }

        return image;
    }
};

```

### DFS solution ...

```cpp
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originalColor = image[sr][sc];

        if (originalColor != newColor) 
        {
            dfs(image, sr, sc, originalColor, newColor);
        }
        return image;
    }

private:
    void dfs(vector<vector<int>>& image, int x, int y, int originalColor, int newColor) {
        // Check boundaries and whether the current cell is of the original color
        if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != originalColor) 
        {
            return;
        }

        // Change the color of the current cell
        image[x][y] = newColor;

        // Call dfs for all 4 directions
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dx, dy] : directions) 
        {
            dfs(image, x + dx, y + dy, originalColor, newColor);
        }
    }
};

```

