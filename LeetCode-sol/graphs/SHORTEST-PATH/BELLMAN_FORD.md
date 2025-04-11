## Bellman-Ford operates by iterating through all edges, so it works best with an edge list rather than an adjacency list.

The Bellman-Ford algorithm has the following time and space complexity:

>Time Complexity:
>
The algorithm consists of two main loops. The outer loop runs V-1 times, where V is the number of vertices in the graph. The inner loop iterates over all edges in the graph. If we denote E as the number of edges, the overall time complexity can be expressed as `O(V * E)`. This means that the algorithm is efficient for graphs with a relatively small number of edges compared to the number of vertices.

>Space Complexity:
   
The space complexity of the Bellman-Ford algorithm is O(V) due to the storage of the distance array, which holds the shortest distance from the source vertex to each of the V vertices. Additionally, the edges are stored in a vector, which requires O(E) space. Therefore, the overall space complexity is O(V + E), but the dominant factor is typically `O(V)` when considering the distance array.

Each edge is represented as a structure or tuple:
```cpp
struct Edge {
    int u, v, wt;
};
```

vector<Edge> edges;

```cpp
vector<tuple<int, int, int>> input = {
    {0, 1, 5},
    {0, 2, 4},
    {1, 2, -3},
    {2, 3, 2}
};

```
## structure 'edge'
```cpp
vector<Edge> edges;
for (auto &[u, v, wt] : input) {
    edges.push_back({u, v, wt});
}

```

```cpp
edges.push_back({u, v, wt});
edges.push_back({v, u, wt});

```

![image](https://github.com/user-attachments/assets/bcae33a7-3ff1-480f-863b-0817c089f91b)


# BELLMAN FORD ALGO
```cpp
struct Edge {
    int u, v, wt;
};

void bellman_ford(int V, vector<Edge>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.wt;
            }
        }
    }

    // Check for negative cycles
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
            cout << "Negative cycle detected\n";
            return;
        }
    }

    // Output
    for (int i = 0; i < V; ++i) {
        cout << "Distance to node " << i << ": ";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

```

# Bellman-Ford with Path Tracking (Shortest Path Sequence)
## We’ll add a parent[] array to reconstruct the shortest path after the distances are calculated.

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, wt;
};

void bellman_ford(int V, vector<Edge>& edges, int src, int dest) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[src] = 0;

    // Relax edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.wt;
                parent[e.v] = e.u;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.wt < dist[e.v]) {
            cout << "Negative cycle detected\n";
            return;
        }
    }

    // Path reconstruction
    if (dist[dest] == INT_MAX) {
        cout << "No path from " << src << " to " << dest << "\n";
        return;
    }

    vector<int> path;
    for (int v = dest; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    // Output
    cout << "Shortest distance: " << dist[dest] << "\n";
    cout << "Path: ";
    for (int node : path) cout << node << " ";
    cout << "\n";
}

```

```cpp
int main() {
    int V = 5;
    vector<Edge> edges = {
        {0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5},
        {1, 4, -4}, {2, 3, -3}, {2, 4, 9}, {3, 1, -2},
        {4, 0, 2}, {4, 3, 7}
    };

    int src = 0, dest = 3;
    bellman_ford(V, edges, src, dest);
}

```


