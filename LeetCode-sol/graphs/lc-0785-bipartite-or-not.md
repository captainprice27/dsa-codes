link : https://leetcode.com/problems/is-graph-bipartite/description/
```cpp

class Solution {
private:
    bool dfs(int node, int colour, vector<vector<int>>& graph,
             int colour_array[]) 
    {
        colour_array[node] = colour; // colouring the current node
        // now we'll check for the adjacent nodes

        for (auto it : graph[node]) 
        {
            if (colour_array[it] == -1) 
            {
                if (dfs(it, !colour, graph, colour_array) == false)
                    return false;
            } 
            else if (colour_array[it] == colour)
                return false;
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int V = graph.size(); // graph is adj list only , its size = total nodes
        int colour_array[V];

        for (int j = 0; j < V; j++)
            colour_array[j] = -1;

        for (int i = 0; i < V; i++) 
        {
            // if not visited before
            if (colour_array[i] == -1)
                if (dfs(i, 0, graph, colour_array) == false)
                    return false; // 0-> starting col
        }
        return true;
    }
};
```
