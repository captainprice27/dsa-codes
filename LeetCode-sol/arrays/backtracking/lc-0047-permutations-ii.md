link : https://leetcode.com/problems/permutations-ii/description/

>The time complexity of this solution is O(n * n!), where n is the number of elements in the input vector. This is because there are n! possible permutations of the elements, and for each permutation, we need to iterate through the elements to check for duplicates and add them to the result vector.

>The space complexity is O(n), where n is the number of elements in the input vector. This is because we are using additional space for the current permutation vector, the used vector to keep track of used elements, and the result vector to store the permutations.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        
        sort(nums.begin(), nums.end());
        backtrack(nums, current, used, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            // Choose the current element
            used[i] = true;
            current.push_back(nums[i]);

            // Recurse
            backtrack(nums, current, used, result);

            // Undo the choice (backtrack)
            used[i] = false;
            current.pop_back();
        }
    }
};


```
