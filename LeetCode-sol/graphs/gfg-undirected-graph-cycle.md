link : https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

### without using binding (advanced feature in c++17)
```cpp
class Solution {
public:
    // Function to detect cycle in an undirected graph using BFS
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCheckCycle(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool bfsCheckCycle(int start, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int, int>> q; // Pair to store (node, parent)
        q.push({start, -1}); // Start node has no parent
        visited[start] = true;

        while (!q.empty()) {
            pair<int, int> nodePair = q.front();
            q.pop();
            int node = nodePair.first;
            int parent = nodePair.second;

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    // A visited node that is not the parent indicates a cycle
                    return true;
                }
            }
        }
        return false;
    }
};
```

### with using binding 

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph using BFS
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCheckCycle(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool bfsCheckCycle(int start, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int, int>> q; // Pair to store (node, parent)
        q.push({start, -1}); // Start node has no parent
        visited[start] = true;

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                } else if (neighbor != parent) {
                    // A visited node that is not the parent indicates a cycle
                    return true;
                }
            }
        }
        return false;
    }
};

```
