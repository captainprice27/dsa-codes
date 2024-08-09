link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/


```cpp
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> leftMaxProfit(n, 0), rightMaxProfit(n, 0);

        int minPrice = prices[0];
        for (int i = 1; i < n; i++) 
        {
            minPrice = min(minPrice, prices[i]);
            leftMaxProfit[i] = max(leftMaxProfit[i - 1], prices[i] - minPrice);
        }

        int maxPrice = prices[n - 1];
        for (int j = n - 2; j >= 0; j--) 
        {
            maxPrice = max(maxPrice, prices[j]);
            rightMaxProfit[j] =
                max(rightMaxProfit[j + 1], maxPrice - prices[j]);
        }
        int profit = 0;
        for (int i = 0; i < n; i++) 
        {
            profit = max(profit, rightMaxProfit[i] + leftMaxProfit[i]);
        }
        return profit;
    }
};

```
