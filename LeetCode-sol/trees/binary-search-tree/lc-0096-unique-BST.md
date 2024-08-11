link : https://leetcode.com/problems/delete-node-in-a-bst/description/     

discussion : https://leetcode.com/problems/unique-binary-search-trees/solutions/31666/dp-solution-in-6-lines-with-explanation-f-i-n-g-i-1-g-n-i/

```cpp

class Solution {
public:
    int numTrees(int n)
  {
        // DP array to store the number of unique BSTs for each number of nodes
        vector<int> G(n + 1, 0);
        
        // Base cases
        G[0] = 1; // An empty tree
        G[1] = 1; // A tree with one node
        
        // Fill the DP array using the recurrence relation
        for (int nodes = 2; nodes <= n; ++nodes)
        {
            for (int root = 1; root <= nodes; ++root)
            {
                G[nodes] += G[root - 1] * G[nodes - root];
            }
        }
        
        // The answer is the number of unique BSTs with n nodes
        return G[n];
    }
};
```
