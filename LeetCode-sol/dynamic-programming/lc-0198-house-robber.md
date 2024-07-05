// link : https://leetcode.com/problems/house-robber/description/ 

## brute force (testcases passed but TLE)
> The time complexity of this solution is O(2^n) because for each house, we are making two recursive calls (pick and unpick) which results in an exponential number of recursive calls. 

> The space complexity is O(n) because the recursive calls use a maximum of n levels on the call stack due to the depth of the recursion.
```cpp
class Solution {
private:
    int fn(int index ,vector<int> &nums)
    {
        // edge cases
        if(index == 0) return nums[0];
        if(index < 0) return 0 ;

        int pick = nums[index] + fn(index-2,nums);
        int unpick = 0 + fn(index-1,nums);
        return max(pick,unpick);
    }
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        return fn(n-1,nums);    
    }
};
```
## memoization using top down (Mem limit exceeded)

> The time complexity of this solution is O(n) because we are using memoization to avoid redundant calculations and only calculating each subproblem once.
> The space complexity is also O(n) because we are using a memoization array of size n to store the results of subproblems. This approach reduces the time complexity from exponential to linear by storing and reusing the results of subproblems.

```cpp
class Solution {
private:
    int fn(int index, vector<int>& nums , vector<int> dp) {
        // edge cases
        if (index == 0)
            return nums[0];
        if (index < 0)
            return 0;
        // if already visited , don't compute again and return the val
        //below is the most imp line .. since it reduces time complx. 
        if(dp[index] != -1) return dp[index]; 

        int pick = nums[index] + fn(index - 2, nums,dp);
        int unpick = 0 + fn(index - 1, nums,dp);
        return dp[index] = max(pick, unpick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return fn(n - 1, nums,dp);
    }
};
```

## tabulation form (accepted) 

>The time complexity of this solution is O(n) because we are iterating through the input array once to calculate the maximum amount that can be robbed.
>The space complexity is also O(n) because we are using a DP array of size n to store the maximum amount that can be robbed at each house.

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        // edge cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) 
        {
            int pick = nums[i] + dp[i-2]; // pick current
            int unpick = 0 + dp[i-1] ; // unpick current
            dp[i] = max(pick,unpick);
        }
        
        return dp[n-1]; // n-1 is the n'th element
    }
};

```

## space optimization technique(acc , fast)
>The time complexity of this solution is O(n) because we are iterating through the input array of size n once.
>The space complexity is O(1) because we are using only a constant amount of extra space regardless of the input size. We are not using any additional data structures that grow with the input size, so the space compl

```cpp
//SPACE OPTIMIZATION TECHNIQUE
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prev2 = nums[0];
        int prev = max(nums[1],nums[0]) ; 

        // vector<int> dp(n, 0);
        // edge cases
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) 
        {
            // int pick = nums[i] + dp[i-2]; // pick current
            // int unpick = 0 + dp[i-1] ; // unpick current
            // dp[i] = max(pick,unpick);
            int pick = nums[i] + prev2 ;
            int unpick = 0 + prev ;
            int curr_i = max(pick,unpick) ;
            prev2 = prev ; 
            prev = curr_i ;
        }
        
        // return dp[n-1]; // n-1 is the n'th element
        return prev ;
    }
};
```
a more furnished one excluding comments....
```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int pick = nums[i] + prev2;
            int unpick = prev;
            int curr_i = max(pick, unpick);
            prev2 = prev;
            prev = curr_i;
        }
        
        return prev;
    }
};

```

