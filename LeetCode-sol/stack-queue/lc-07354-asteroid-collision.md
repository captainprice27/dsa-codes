link : https://leetcode.com/problems/asteroid-collision/description/  

also discussion section of : https://leetcode.com/problems/asteroid-collision/solutions/109694/java-c-clean-code/

> overall, there are totally 4 scenarios will happen: **1.(+ +)  2.(- -)  3. (+ -)  4.(- +)**
when collision happens: only 3 which is **(+ -)**
use a stack to keep track of the previous and compare current value with previous ones

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
