link : https://leetcode.com/problems/combination-sum-iv/description/

## backtracking (TLE)

>The time complexity of this solution is exponential, as it involves backtracking through all possible combinations of numbers in the input array to reach the target sum. The worst-case time complexity is O(2^N), where N is the number of elements in the input array.

>The space complexity is also exponential, as the recursive calls create a new stack frame for each combination of numbers. The worst-case space complexity is O(N), where N is the number of elements in the input array.


```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, target, count);
        return count;
    }

private:
    void backtrack(vector<int>& nums, int target, int& count) {
        if (target == 0) {
            count++;
            return;
        }
        if (target < 0) return;

        for (int num : nums) {
            backtrack(nums, target - num, count);
        }
    }
};

```

## backtracking with memo

>The time complexity of this solution is O(target * n), where n is the number of elements in the nums array and target is the target sum. This is because for each target value from 1 to target, we iterate through all the elements in the nums array to calculate the number of valid combinations. 

>The space complexity is O(target) due to the memoization table used to store the results of subproblems. This table can have at most target entries, one for each possible target value.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> memo;
        return backtrack(nums, target, memo);
    }

private:
    int backtrack(vector<int>& nums, int target, unordered_map<int, int>& memo) {
        if (target == 0) return 1; // Found a valid combination
        if (target < 0) return 0; // Exceeded the target, invalid combination
        
        if (memo.find(target) != memo.end()) return memo[target];
        
        int count = 0;
        for (int num : nums) {
            count += backtrack(nums, target - num, memo);
        }
        
        memo[target] = count; // Store the result in memoization table
        return count;
    }
};

```

### tabulation

>The time complexity of this solution is O(target * n), where n is the number of elements in the nums array and target is the target sum. This is because we are iterating through the target sum and for each value, we are iterating through each element in the nums array.

>The space complexity is O(target) because we are using a vector of size target + 1 to store the dynamic programming array dp.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; ++i) {
            for (int num : nums) {
                if (i >= num) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};

```
