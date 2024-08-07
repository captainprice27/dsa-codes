link : https://leetcode.com/problems/daily-temperatures/description/

```cpp

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) 
        {
            // While the current temperature is greater than the temperature at
            // the index at the top of the stack, pop the stack and calculate
            // the difference.
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) 
            {
                int idx = st.top();
                st.pop();
                answer[idx] = i - idx;
            }
            // Push the current index onto the stack
            st.push(i);
        }

        return answer;
    }
};

```
