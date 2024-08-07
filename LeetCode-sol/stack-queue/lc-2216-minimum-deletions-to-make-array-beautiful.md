link :  https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

```cpp
class Solution {
public:
    int minDeletion(vector<int>& nums) 
    {
        stack<int> st;

        for (int num : nums) 
        {
            // If stack size is even, it means the next index in the "beautiful"
            // array would be even
            if (!st.empty() && st.size() % 2 == 1 && st.top() == num) 
            {
                continue; // Simulate deletion by skipping the current element
            }
            st.push(num);
        }

        // If the size of the stack is odd, pop one element to make it even
        if (st.size() % 2 == 1) 
        {
            st.pop();
        }

        // Number of deletions = original size of nums - size of stack
        return nums.size() - st.size();
    }
};

```
