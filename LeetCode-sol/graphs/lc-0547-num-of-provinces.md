link : https://leetcode.com/problems/number-of-provinces/

### USING DFS TECHNIQUE ... same xan be done using BFS also

> Time Complexity:
The time complexity of this solution is O(V^2) where V is the number of vertices in the graph. This is because we are iterating over the entire adjacency matrix to convert it into an adjacency list, which takes O(V^2) time. Additionally, we are performing a DFS traversal on each node, which also takes O(V) time.

>Space Complexity:
The space complexity of this solution is O(V) where V is the number of vertices in the graph. This is because we are using an adjacency list to represent the graph, which takes O(V) space. Additionally, we are using a visited array of size V to keep track of visited nodes during the DFS traversal.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // dfs traversal function
    void dfs(int node, vector<int> adj[], vector<int>& vis) 
    {
        // mark the node as visited
        vis[node] = 1;
        for (auto it : adj[node]) 
        {
            if (!vis[it]) 
            {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {    
        int V = isConnected.size();
        vector<int> adj[V];

        // to change adjacency matrix to list
        for (int i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                // self nodes are not considered
                if (isConnected[i][j] == 1 && i != j) 
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0); // initialize visited array with 0
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            // if the node is not visited
            if (!vis[i]) 
            {
                // counter to count the number of provinces
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};

```
