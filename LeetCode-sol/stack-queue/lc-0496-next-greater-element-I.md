link : https://leetcode.com/problems/next-greater-element-i/description/

> The time complexity of this solution is O(N + M), where N is the size of nums1 and M is the size of nums2. This is because we iterate through both nums1 and nums2 once to fill the map with next greater elements. The stack operations also take O(1) time complexity.

>The space complexity of this solution is O(M), where M is the size of nums2. This is because we use a stack and a map to store the next greater elements for each element in nums2.

```cpp

class Solution 
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> ngeMap; 
        // Map to store next greater element for  each element in nums2
        stack<int> s;   // Monotonic stack

        // Traverse nums2 and fill the map with next greater elements
        for (int num : nums2) 
        {
            while (!s.empty() && s.top() < num) 
            {
                ngeMap[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        // For remaining elements in stack, there's no greater element, so map to -1
        while (!s.empty()) 
        {
            ngeMap[s.top()] = -1;
            s.pop();
        }

        // Prepare the result for nums1 based on the map
        vector<int> result;
        for (int num : nums1) 
        {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};
```
