link : https://leetcode.com/problems/next-greater-element-ii/

>The time complexity of this solution is O(n) where n is the number of elements in the input array. This is because we traverse the array twice, but each element is pushed and popped from the stack at most once, resulting in a linear time complexity.

>The space complexity is also O(n) because we use a stack to store indexes of elements, and in the worst case scenario, the stack could contain all n elements of the input array.

```cpp
// in circ array we concatenate same array twice
// total size  = 2*n , and nums[i] == nums[i+n]
class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize result array with -1
        stack<int> s;              // Stack to maintain indexes of elements

        // Traverse the array twice to simulate the circular behavior
        for (int i = 0; i < 2 * n; i++) 
        {   
            int index = i % n ; // modified index to cater circ array ...
            int num = nums[index]; // Access the element in a circular way
            while (!s.empty() && nums[s.top()] < num) 
            {
                result[s.top()] = num;
                s.pop();
            }

            if (i < n) 
            {
                s.push(i); // Only push the first n elements' indexes
            }
        }

        return result;
    }
};
