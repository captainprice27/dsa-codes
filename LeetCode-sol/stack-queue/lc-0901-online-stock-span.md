link : https://leetcode.com/problems/online-stock-span/

```cpp

class StockSpanner 
{
public:
    // Stack to store pairs of (price, span)
    stack<pair<int, int>> st;

    StockSpanner() 
    {
        // No initialization needed as the stack is handled automatically
    }

    int next(int price) 
    {
        int span = 1;

        // While the stack is not empty and the current price is greater than
        // or equal to the price at the top of the stack
        while (!st.empty() && st.top().first <= price) 
        {
            span += st.top().second;
            st.pop();
        }

        // Push the current price and its calculated span onto the stack
        st.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

```
