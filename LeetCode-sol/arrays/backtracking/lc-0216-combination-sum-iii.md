link : https://leetcode.com/problems/combination-sum-iii/description/


>The time complexity of this solution is O(9^k) because for each position in the combination, we have 9 choices (from 1 to 9) and we have k positions.
>
>The space complexity is O(k) because the recursion depth can go up to k levels due to the backtracking algorithm.


```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(result, combination, k, n, 1);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& combination, int k,
                   int n, int start) {
        if (k == 0 && n == 0) {
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            if (i > n)
                break; // If the current number is greater than the remaining
                       // target, no point in continuing

            combination.push_back(i);
            backtrack(result, combination, k - 1, n - i,
                      i + 1);       // Move to the next number
            combination.pop_back(); // Backtrack
        }
    }
};


```
