link : https://leetcode.com/problems/spiral-matrix-iii/description/

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart) 
    {
        vector<vector<int>> result;
        result.push_back({rStart, cStart}); // Start with the initial position

        // Direction vectors for East, South, West, and North (right, down,
        // left, up)
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int num_steps = 1; // Number of steps to take in a given direction
        int dir_idx = 0;   // Start with direction 0 (east)

        while (result.size() < rows * cols) 
        {
            for (int i = 0; i < 2; i++) 
            { // Move in pairs of two directions
                                          // (e.g., right and down)
                for (int step = 0; step < num_steps; step++) 
                {
                    rStart += directions[dir_idx].first;
                    cStart += directions[dir_idx].second;

                    // Check if the position is within bounds
                    if (rStart >= 0 && rStart < rows && cStart >= 0 &&
                        cStart < cols) 
                    {
                        result.push_back({rStart, cStart});
                    }
                }
                // Change direction clockwise
                dir_idx = (dir_idx + 1) % 4;
            }
            num_steps++; // Increase the step count after completing a full loop
        }

        return result;
    }
};


```
