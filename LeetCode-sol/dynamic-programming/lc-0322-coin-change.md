link : https://leetcode.com/problems/coin-change/   

>The time complexity of this solution is O(n * m), where n is the amount and m is the number of coins. This is because we iterate through the amount from 1 to amount and for each amount, we iterate through all the coins.

>The space complexity is O(n), where n is the amount. This is because we use a dp array of size amount + 1 to store the minimum number of coins needed to make each amount.

```cpp
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // the max val of dp array can be (amount+1) , if there are suppose only
        // 1 rs coin , hence we can initialise with (amount+1) as well 10e4 is
        // chosen since 0 <= amount <= 10^4 given ...
        vector<int> dp(amount + 1, 10e4 + 1);
        // base case
        if (n == 0)
            return -1;
        dp[0] = 0; // since coin value is +ve
        for (int i = 1; i <= amount; i++) {
            for (auto& coin : coins) {
                if ((i - coin) >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }

        return dp[amount] == (10e4 + 1) ? -1 : dp[amount];
    }
};

```
