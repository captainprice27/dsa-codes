link : https://leetcode.com/problems/minimum-cost-for-tickets/description/

```cpp
// costs[0] == 1 day pass , costs[1]c== 7 day pass , costs[2] == 30 day pass
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int> dp(366, 0);

        unordered_set<int> travelDays(days.begin(), days.end()); 
        // set for quick lookup of travel days

        for (int i = 1; i <= 365; i++) {
            if (travelDays.find(i) == travelDays.end()) 
            {
                // If it's not a travel day, cost is the same as the previous day
                dp[i] = dp[i - 1];
            } 
            else 
            {
                // Calculate the minimum cost for this travel day
                dp[i] = dp[i - 1] + costs[0]; // 1-day pass

                // 7-day pass, check if 'i' is at least 7 to avoid out of bounds
                if (i >= 7) 
                {
                    dp[i] = min(dp[i], dp[i - 7] + costs[1]);
                } 
                else // i < 7 but maybe say 5*(one-day) pass > a 7-day pass
                {
                    dp[i] = min(dp[i], costs[1]);
                }

                // 30-day pass, check if i is at least 30 to avoid out of bounds
                if (i >= 30) 
                {
                    dp[i] = min(dp[i], dp[i - 30] + costs[2]);
                } 
                else 
                {
                    dp[i] = min(dp[i], costs[2]);
                }
            }
        }

        return dp[365]; // Return the minimum cost to cover all travel days
    }
};


```
