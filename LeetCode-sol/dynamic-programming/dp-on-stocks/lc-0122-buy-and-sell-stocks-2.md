link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0, minPrice = 1e5;
        for (int i = 0; i < prices.size(); i++) 
        {
            minPrice = min(minPrice, prices[i]);
            if (prices[i] > minPrice) 
            {
                profit += prices[i] - minPrice;
            }
            minPrice = prices[i];
        }
        return profit;
    }
};

```
