link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

>The time complexity of this solution is O(n), where n is the number of prices in the input vector. This is because we iterate through the prices array once to calculate the maximum profit.

>The space complexity is O(1) because we are using only a constant amount of extra space, regardless of the input size. We are only using two variables (hold and cash) to keep track of the maximum profit when holding a stock and when not holding any stock.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;

        int hold = -prices[0];  // Max profit when holding a stock
        int cash = 0;           // Max profit when not holding any stock

        for (int i = 1; i < n; ++i) {
            hold = max(hold, cash - prices[i]);
            cash = max(cash, hold + prices[i] - fee);
        }

        return cash;  // Max profit at the end of the last day
    }
};


```
