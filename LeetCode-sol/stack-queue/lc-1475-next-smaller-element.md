link : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/
#### same concept as of next smaller element code ...

>The time complexity of this solution is O(n) where n is the number of prices in the input array. This is because we iterate through the prices array once and perform constant time operations for each price.

>The space complexity is O(n) as well. This is because we use a stack to store indices of prices and the result array to store the final prices after applying discounts. Both of these data structures have a space complexity of O(n) as they can potentially store all n prices.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> result(n);
        stack<int> s; // Stack to store indices of the prices array

        for (int i = 0; i < n; i++) 
        {
            // While there are elements in the stack and the current price is
            // less than or equal to the price corresponding to the index at the
            // top of the stack
            while (!s.empty() && prices[i] <= prices[s.top()]) 
            {
                int index = s.top();
                s.pop();
                result[index] = prices[index] - prices[i]; // Apply the discount
            }
            // Push the current index onto the stack
            s.push(i);
        }

        // For remaining indices in the stack, no discounts were found
        while (!s.empty()) 
        {
            int index = s.top();
            s.pop();
            result[index] = prices[index];
        }

        return result;
    }
};

```
