link : https://leetcode.com/problems/partition-array-for-maximum-sum/description

## tabulation (bottom-up)
>The time complexity of this solution is O(n*k), where n is the length of the input array 'arr' and k is the partition size. This is because we have two nested loops, one iterating over the length of the array and the other iterating up to the partition size k.

>The space complexity is O(n) because we are using a DP array of size n+1 to store the maximum sum values for each subarray of 'arr'.
```cpp
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // base case
        
        // here 'i' --> arr of length 'i'
        for (int i = 1; i <= n; i++) 
        {
            int max_Element = 0;
            for (int j = 1; j <= k && (i - j) >= 0; j++) 
            {
                max_Element = max(max_Element, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j] + max_Element * j);
            }
        }
        
        return dp[n];
    }
};
```

## space optimisation (O(k) space , same time)
```cpp
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(k, 0);
        
        for (int i = 1; i <= n; ++i) {
            int maxElement = 0;
            int maxSum = 0;
            for (int j = 1; j <= k && i - j >= 0; ++j) {
                maxElement = max(maxElement, arr[i - j]);
                maxSum = max(maxSum, dp[(i - j) % k] + maxElement * j);
            }
            dp[i % k] = maxSum;
        }
        
        return dp[n % k];
    }
};
```
