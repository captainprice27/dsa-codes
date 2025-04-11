# 1. Single Source – All Destinations Dijkstra
# ✅ Finds shortest distance from a source to all nodes

The provided implementation of Dijkstra's algorithm has the following time and space complexity analysis:

>**Time Complexity:**          
1. The algorithm uses a priority queue (min-heap) to efficiently retrieve the node with the smallest distance. The priority queue operations (insertion and extraction) take O(log V) time, where V is the number of vertices.
2. Each vertex is pushed into the priority queue at most once, leading to O(V) insertions.
3. For each vertex, we explore its adjacent edges. In the worst case, if the graph is dense, there can be up to E edges, where E is the number of edges in the graph. For each edge, we may perform an update operation which also takes O(log V) time due to the priority queue.
4. Therefore, the overall time complexity can be expressed as **O((V + E) log V)**. In a dense graph, where E is close to V^2, this can be approximated as O(V^2 log V).

>**Space Complexity:**
1. The space complexity is primarily determined by the storage of the graph and the distance array. The adjacency list representation of the graph requires O(V + E) space.
2. The distance array requires O(V) space to store the shortest distances from the source to each vertex.
3. The priority queue can also hold up to O(V) elements in the worst case.
4. Thus, the overall space complexity is **O(V + E)**.

In summary, the time complexity is **O((V + E) log V)** and the space complexity is **O(V + E)**.

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

void dijkstra(int V, vector<vector<pii>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, wt] : adj[u]) {
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

```

# 2. Single Source – Single Destination Dijkstra (Early Stop)
# ✅ Stop as soon as the destination is reached for efficiency

```cpp
int dijkstraSingleDest(int V, vector<vector<pii>>& adj, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (u == dest) return dist[dest]; // Early stop!

        if (d > dist[u]) continue;

        for (auto [v, wt] : adj[u]) {
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return -1; // dest not reachable
}

```

# 3. Dijkstra with Path Reconstruction
# ✅ Print both shortest distance and path (as node sequence)

```cpp
void dijkstraWithPath(int V, vector<vector<pii>>& adj, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pii, vector<pii>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, wt] : adj[u]) {
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No path from " << src << " to " << dest << "\n";
        return;
    }

    // Reconstruct path
    vector<int> path;
    for (int v = dest; v != -1; v = parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());

    // Output
    cout << "Shortest distance: " << dist[dest] << "\n";
    cout << "Path: ";
    for (int node : path) cout << node << " ";
    cout << "\n";
}

```

# example usage : 
```cpp
int main() {
    int V = 6;
    vector<vector<pii>> adj(V);

    // Sample undirected graph
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4}, {0, 2, 1}, {2, 1, 2}, {1, 3, 1},
        {2, 3, 5}, {3, 4, 3}, {4, 5, 1}
    };

    for (auto [u, v, w] : edges) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected
    }

    int source = 0, destination = 5;

    cout << "\n--- Single Source ---\n";
    dijkstra(V, adj, source);

    cout << "\n--- Single Source Single Destination ---\n";
    int shortest = dijkstraSingleDest(V, adj, source, destination);
    cout << "Shortest distance from " << source << " to " << destination << ": " << shortest << "\n";

    cout << "\n--- Shortest Path and Distance ---\n";
    dijkstraWithPath(V, adj, source, destination);
}

```
