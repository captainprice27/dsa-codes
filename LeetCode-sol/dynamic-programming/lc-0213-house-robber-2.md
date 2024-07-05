// link : https://leetcode.com/problems/house-robber-ii/

### tstcases passed but heap buffer overflow ...
> The time complexity of this solution is O(n) because we are iterating through the array once to calculate the maximum amount that can be robbed.
> The space complexity is also 2*O(n) because we are using two arrays of size n to store the maximum amount that can be robbed when excluding the first and last elements.
```cpp
// in this problem , first abd last element can't be together
// so what we will do is : we will calculate the question by excluding
//first element and then excluding last elem and then taking max of two 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // EXCLUDE LAST ELEMENT
        vector<int> dp(n, 0);
        // initialising
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n-1; i++) 
        {
            int pick = nums[i] + dp[i-2]; // pick current
            int unpick = 0 + dp[i-1] ; // unpick current
            dp[i] = max(pick,unpick);
        }
        int ans1 = dp[n-2] ;

        // EXCLUDE FIRST ELEMENT
        vector<int> dp2(n, 0);
        //dp[0] = nums[0];
        
        dp2[1] = nums[1];
        dp2[2] = max(nums[1],nums[2]);
        
        for (int i = 3; i < n; i++) 
        {
            int pick_2 = nums[i] + dp2[i-2]; // pick current
            int unpick_2 = 0 + dp2[i-1] ; // unpick current
            dp2[i] = max(pick_2,unpick_2);
        }
        //return dp[n-1]; // n-1 is the n'th element
        int ans2 = dp2[n-1];

        return max(ans1,ans2);
    }
};

```

## optimised approach with space optimisation approach ...
> JUST COPY PASTE SPACE OPTI ALGO FROM HOUSE-ROBBER-2 THEN SOME TRICKS
>
>The time complexity of this solution is O(n) because we are iterating through the input array once to calculate the maximum amount that can be robbed.
> The space complexity is O(n) because we are using two additional arrays to store the subarrays excluding the first and last elements.
> 
```cpp
class Solution {

    private : 
    int helper(vector<int> &nums)
    {
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

public:
    int rob(vector<int>& nums) 
    {   
        int n = nums.size();
        if(n == 1) return nums[0] ;
        vector<int> temp1 , temp2 ;
        for(int i=0;i<n;i++)
        {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1),helper(temp2));
    }
};

```
