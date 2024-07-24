link : https://leetcode.com/problems/surrounded-regions/

```cpp
class Solution 
{
public:
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();

        // Mark boundary-connected 'O's with 'T'
        for (int i = 0; i < m; ++i) 
        {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for (int j = 0; j < n; ++j) 
        {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }

        // Replace all 'O's with 'X' and revert 'T' back to 'O'
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;

        board[i][j] = 'T';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
```
