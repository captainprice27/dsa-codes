link : https://leetcode.com/problems/coin-change-ii/description/

> The time complexity of this solution is O(amount * n), where n is the number of coins and amount is the target amount. This is because we iterate through each coin for each amount from 1 to the target amount.

>The space complexity is O(amount) because we are using a vector of size amount + 1 to store the number of ways to make each amount using the given coins.

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;  // There's one way to make 0 amount, which is by using no coins

        for (const int& coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};

```
