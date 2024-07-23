link : 

### dfs implementation : 
```cpp
class Solution {
  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs; // To store the DFS traversal
        vector<bool> visited(V, false); // To keep track of visited nodes

        // Helper function to perform DFS
        dfsHelper(0, adj, visited, dfs);

        return dfs;
    }

  private:
    void dfsHelper(int node, vector<int> adj[], vector<bool>& visited, vector<int>& dfs) {
        visited[node] = true;
        dfs.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, dfs);
            }
        }
    }
};
```

### dfs --> ADJACENCY MATRIX **
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dfsOfGraph(int V, vector<vector<int>>& adjMatrix) {
        vector<int> dfs; // To store the DFS traversal
        vector<bool> visited(V, false); // To keep track of visited nodes

        // Helper function to perform DFS
        dfsHelper(0, adjMatrix, visited, dfs);

        return dfs;
    }

  private:
    void dfsHelper(int node, vector<vector<int>>& adjMatrix, vector<bool>& visited, vector<int>& dfs) {
        visited[node] = true;
        dfs.push_back(node);

        for (int neighbor = 0; neighbor < adjMatrix.size(); neighbor++) {
            if (adjMatrix[node][neighbor] == 1 && !visited[neighbor]) {
                dfsHelper(neighbor, adjMatrix, visited, dfs);
            }
        }
    }
};

int main() {
    int V = 5;
    vector<vector<int>> adjMatrix = {
        {0, 1, 1, 0, 0}, // Edges from node 0
        {1, 0, 0, 1, 1}, // Edges from node 1
        {1, 0, 0, 0, 0}, // Edges from node 2
        {0, 1, 0, 0, 0}, // Edges from node 3
        {0, 1, 0, 0, 0}  // Edges from node 4
    };
    Solution sol;
    vector<int> dfs = sol.dfsOfGraph(V, adjMatrix);
    for (int node : dfs) {
        cout << node << " ";
    }
    return 0;
}

```
