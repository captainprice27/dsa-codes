```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph using DFS
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCheckCycle(i, adj, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfsCheckCycle(int node, vector<int> adj[], vector<bool>& visited, int parent) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCheckCycle(neighbor, adj, visited, node)) {
                    return true;
                }
            } else if (neighbor != parent) {
                // A visited node that is not the parent indicates a cycle
                return true;
            }
        }
        return false;
    }
};

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in an undirected graph using DFS
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCheckCycle(i, adj, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfsCheckCycle(int node, vector<int> adj[], vector<bool>& visited, int parent) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfsCheckCycle(neighbor, adj, visited, node)) {
                    return true;
                }
            } else if (neighbor != parent) {
                // A visited node that is not the parent indicates a cycle
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> adj[] = {
        {1, 2},
        {0, 2},
        {0, 1, 3},
        {2, 4},
        {3}
    };
    int V = 5;
    cout << sol.isCycle(V, adj) << endl; // Output: 1 (true)
    return 0;
}

```
```
