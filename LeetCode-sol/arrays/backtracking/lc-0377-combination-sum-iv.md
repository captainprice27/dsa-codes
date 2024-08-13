link : https://leetcode.com/problems/combination-sum-iv/description/

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
