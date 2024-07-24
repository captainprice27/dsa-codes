link : https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

### adjacency list implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs; // To store the BFS traversal
        vector<bool> visited(V, false); // To keep track of visited nodes

        queue<int> q;
        q.push(0); // Starting the BFS from node 0 (assuming 0-indexed nodes)
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return bfs;
    }
};

```

```cpp

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> &adj) {
        vector<int> bfs; // To store the BFS traversal
        vector<bool> visited(V, false); // To keep track of visited nodes

        queue<int> q;
        q.push(0); // Starting the BFS from node 0 (assuming 0-indexed nodes)
        visited[0] = true;

        while (!q.empty()) 
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int neighbor : adj[node]) 
            {
                if (!visited[neighbor]) 
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return bfs;
    }
};
```

### adjacency matrix
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<vector<int>>& adjMatrix) {
        vector<int> bfs; // To store the BFS traversal
        vector<bool> visited(V, false); // To keep track of visited nodes

        queue<int> q;
        q.push(0); // Starting the BFS from node 0 (assuming 0-indexed nodes)
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int neighbor = 0; neighbor < V; neighbor++) {
                if (adjMatrix[node][neighbor] == 1 && !visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        return bfs;
    }
};

```
