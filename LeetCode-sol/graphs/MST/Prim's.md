# PRIM'S ALGORITHM

>We build the Minimum Spanning Tree (MST) by starting from any node and
greedily picking the smallest weight edge that connects a visited node to an
unvisited node.

>Building the MST: `O(E log V)`
Each edge can be pushed once into the priority queue
Priority queue operations take `log V`
>
>Space Complexity:
`O(V + E)` for adjacency list
`O(V)` for visited array and priority queue

```CPP
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int primMST(int n, vector<vector<pair<int, int>>> &adj) {

  vector<bool> visited(n, false);
  // priority queue
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  int mst_cost = 0;

  // Start from node 0

  pq.push({0, 0}); // {weight, node}

  while (!pq.empty())
  {
    auto [wt, u] = pq.top();
    pq.pop();

    if (visited[u]) continue;
    visited[u] = true;
    mst_cost += wt;

    for (auto &[v, w] : adj[u]) {
    if (!visited[v]) {
      pq.push({w, v});
      }
    }
  }

  return mst_cost;
}

```

## tuple-based implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void primsAlgorithm(int n, vector<vector<pair<int, int>>>& adj) {
    // Priority queue to store tuples in the form <weight, parent, node>
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

    vector<bool> inMST(n, false); // To track nodes already in MST
    vector<int> key(n, INT_MAX); // To store the minimum weight to reach a node
    vector<int> parent(n, -1);   // To store the parent of each node in MST

    // Start with the first node (assuming node indices are 0-based)
    key[0] = 0;
    pq.emplace(0, -1, 0); // <weight, parent, node>

    while (!pq.empty()) {
        auto [weight, uParent, u] = pq.top();
        pq.pop();

        if (inMST[u]) continue; // Skip already processed nodes

        inMST[u] = true;  // Mark the node as included in MST
        parent[u] = uParent;

        // Explore all neighbors of the current node
        for (auto& [v, wt] : adj[u]) {
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                pq.emplace(wt, u, v); // Push new potential edges to the PQ
            }
        }
    }

    // Printing the MST
    cout << "Edge\tWeight\n";
    for (int i = 1; i < n; ++i) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adj(n);

    // Example graph
    adj[0].emplace_back(1, 2);
    adj[0].emplace_back(3, 6);
    adj[1].emplace_back(0, 2);
    adj[1].emplace_back(2, 3);
    adj[1].emplace_back(3, 8);
    adj[1].emplace_back(4, 5);
    adj[2].emplace_back(1, 3);
    adj[2].emplace_back(4, 7);
    adj[3].emplace_back(0, 6);
    adj[3].emplace_back(1, 8);
    adj[4].emplace_back(1, 5);
    adj[4].emplace_back(2, 7);

    primsAlgorithm(n, adj);

    return 0;
}

```
