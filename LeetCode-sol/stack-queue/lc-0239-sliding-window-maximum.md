link : https://leetcode.com/problems/sliding-window-maximum/

```cpp

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_window;
        deque<int> dq; // Deque to store indices of elements

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) 
        {
            // Remove indices outside the window from front of deque
            if (!dq.empty() && dq.front() == i - k) 
            {
                dq.pop_front();
            }

            // Remove smaller elements from back of deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) 
            {
                dq.pop_back();
            }

            // Add current index to deque
            dq.push_back(i);

            // Add maximum element of current window to result
            if (i >= k - 1) 
            {
                max_window.push_back(nums[dq.front()]);
            }
        }

        return max_window;
    }
};
```
