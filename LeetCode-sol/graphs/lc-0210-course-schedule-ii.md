link  https://leetcode.com/problems/course-schedule-ii/  

###  Topological Sort using BFS (Kahn's Algorithm)
> The time complexity of this solution is O(V + E), where V is the number of courses and E is the number of prerequisites. This is because we are iterating through all the courses and prerequisites to build the adjacency list and in-degree array, and then performing a BFS traversal on the graph.

>The space complexity is also O(V + E) because we are using additional space to store the adjacency list, in-degree array, queue, and result vector.

>Overall, this solution is efficient in terms of time and space complexity for finding the order of courses to take given the prerequisites.
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) 
        {
            adj[pre[1]].push_back(pre[0]);

            inDegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) 
        {
            if (inDegree[i] == 0) 
            {
                q.push(i);
            }
        }

        vector<int> result;
        
        while (!q.empty()) 
        {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (int nextCourse : adj[course]) 
            {
                inDegree[nextCourse]--;

                if (inDegree[nextCourse] == 0) 
                {
                    q.push(nextCourse);
                }
            }
        }

        if (result.size() == numCourses) 
        {
            return result;
        } 
        else 
        {
            return {};
        }
    }
};

```
