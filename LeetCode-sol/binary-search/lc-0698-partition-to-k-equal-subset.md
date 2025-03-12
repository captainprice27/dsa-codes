link : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

***Intuition***   
> We need to divide the array into k non-empty subsets with equal sums.   
> Key Check: The total sum of the array must be divisible by k. If not, it’s impossible.   
> Target Sum: If possible, each subset must sum to total_sum / k.    
> Approach: Use backtracking to try assigning each number to one of the k subsets, ensuring no subset exceeds the target sum.    
> Optimization: Sort the array in descending order to fail faster with larger numbers and reduce the search space.    
> This is similar to the cookie distribution problem but with a fixed target sum (total_sum / k) instead of minimizing the maximum sum.     

```cpp
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % k != 0 || n < k) return false;
        
        int target = total / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > target) return false;
        
        vector<int> subsets(k, 0);
        return backtrack(nums, subsets, 0, target, k);
    }
    
private:
    bool backtrack(vector<int>& nums, vector<int>& subsets, int pos, int target, int k) {
        if (pos == nums.size()) return true;
        
        for (int i = 0; i < k; i++) {
            if (subsets[i] + nums[pos] <= target) {
                subsets[i] += nums[pos];
                if (backtrack(nums, subsets, pos + 1, target, k)) return true;
                subsets[i] -= nums[pos];
                if (subsets[i] == 0) break;
            }
        }
        return false;
    }
};
```

The time complexity of the `canPartitionKSubsets` function can be analyzed as follows:

1. The function first checks if the total sum of the array is divisible by `k` and if the largest number is less than or equal to the target. These checks take O(n) time, where n is the number of elements in the `nums` array.

2. The main part of the algorithm involves a backtracking approach, which explores all possible ways to partition the array into `k` subsets. In the worst case, the algorithm may explore all possible combinations of placing each number into one of the `k` subsets. This results in a time complexity of O(k^n), where n is the number of elements in `nums`. However, due to the pruning that occurs when subsets exceed the target or when a subset is empty, the average case is often much better than the worst case.

The space complexity is primarily determined by the space used for the `subsets` vector and the recursion stack:

1. The `subsets` vector requires O(k) space to store the current sums of each subset.

2. The recursion stack can go as deep as the number of elements in `nums`, leading to a space complexity of O(n) in the worst case.

Overall, the space complexity is O(k + n). 

In summary, the time complexity is O(k^n) in the worst case, and the space complexity is O(k + n).
