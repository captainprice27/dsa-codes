link : https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

>The time complexity of this solution is O(n) because we are iterating through the array once from right to left.
>The space complexity is also O(n) because we are using a stack to store elements.

```cpp
class Solution
{
    public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> result(n); // Vector to store the next greater elements
        stack<long long> s; // Monotonic stack to track elements

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) 
        {
            // Pop elements from the stack that are smaller than or equal to the current element
            while (!s.empty() && s.top() <= arr[i]) 
            {
                s.pop();
            }
            
            // If stack is empty, no greater element to the right
            if (s.empty()) 
            {
                result[i] = -1;
            } 
            else 
            {
                // The top element of the stack is the next greater element
                result[i] = s.top();
            }
            
            // Push the current element onto the stack
            s.push(arr[i]);
        }
        
        return result;
    }
};

```
