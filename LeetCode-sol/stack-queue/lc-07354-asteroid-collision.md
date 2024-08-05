link : https://leetcode.com/problems/asteroid-collision/description/  

>The time complexity of this solution is O(n), where n is the number of asteroids in the input vector. This is because we iterate through each asteroid once and perform constant time operations for each asteroid.

>The space complexity of this solution is O(n), where n is the number of asteroids in the input vector. This is because we use a stack to keep track of the asteroids, and in the worst case scenario, the stack could contain all the asteroids.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;

        for (int asteroid : asteroids) 
        {
            // Process the current asteroid
            bool exploded = false;

            while (!st.empty() && asteroid < 0 && st.top() > 0) 
            {
                if (abs(st.top()) < abs(asteroid)) 
                {
                    st.pop(); // The asteroid in the stack explodes
                } 
                else if (abs(st.top()) == abs(asteroid)) 
                {
                    st.pop(); // Both asteroids explode
                    exploded = true;
                    break;
                } 
                else // abs(st.top()) > abs(asteroid)
                {
                    exploded = true; // The current asteroid explodes
                    break;
                }
            }

            // If the current asteroid didn't explode, push it onto the stack
            if (!exploded) 
            {
                st.push(asteroid);
            }
        }

        // Collect the remaining asteroids from the stack
        int n = st.size();
        vector<int> result(n);
        for (int i = n - 1; i >= 0; i--) 
        {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};

```
