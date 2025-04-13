# Kruskal’s Algorithm
> **Intuition:**
Kruskal's builds the MST by sorting all edges by weight and picking the smallest
edge that doesn’t form a cycle (i.e., connects two different components). We use
DSU (Union-Find) to detect cycles efficiently.
>
### Kruskal’s Steps:
1. Sort all edges in increasing order of weight.
2. Initialize each node as its own parent (DSU).
3. For each edge:
If the two nodes are in different components, add edge to MST and union
them.
Else, skip (would form a cycle).
4. Stop when MST has V-1 edges.


```cpp

#include <bits/stdc++.h>
using namespace std;

// DSU (Disjoint Set Union)
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // Initialize each node as its own parent
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false; // Already in the same set

        if (rank[u] < rank[v]) swap(u, v); // Union by rank
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
        return true;
    }
};

// Kruskal's MST function
int kruskalMST(int n, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end()); // Sort edges by weight

    DSU dsu(n);
    int mstCost = 0;

    for (const auto& [w, u, v] : edges) {
        if (dsu.unite(u, v)) { // Include the edge if it doesn't form a cycle
            mstCost += w;
        }
    }

    return mstCost;
}

// Example usage
int main() {
    int n = 5; // Number of nodes
    vector<tuple<int, int, int>> edges = {
        {2, 0, 1}, {3, 1, 2}, {6, 0, 3}, {8, 1, 3}, {5, 1, 4}, {7, 2, 4}
    };

    int mstCost = kruskalMST(n, edges);

    cout << "Cost of the MST: " << mstCost << endl;
    return 0;
}

```
