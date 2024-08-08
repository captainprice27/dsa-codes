link : https://leetcode.com/problems/spiral-matrix-iv/description/


```cpp

#include <vector>
using namespace std;

// Definition for singly-linked list.
// struct ListNode 
// {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution 
{
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(
            m, vector<int>(n, -1)); // Initialize matrix with -1

        // Direction vectors: right, down, left, up
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir_idx = 0; // Start direction: right

        int r = 0, c = 0; // Starting position
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (head) 
        {
            matrix[r][c] =
                head->val;     // Place current list node value into matrix
            head = head->next; // Move to the next node

            // Calculate next position
            int nr = r + directions[dir_idx].first;
            int nc = c + directions[dir_idx].second;

            // Check if the next position is within bounds and not yet visited
            if (nr > bottom || nr < top || nc > right || nc < left ||
                matrix[nr][nc] != -1) 
            {
                // Change direction (clockwise)
                dir_idx = (dir_idx + 1) % 4;
                nr = r + directions[dir_idx].first;
                nc = c + directions[dir_idx].second;
            }

            // Update the current position
            r = nr;
            c = nc;
        }

        return matrix;
    }
};

```
