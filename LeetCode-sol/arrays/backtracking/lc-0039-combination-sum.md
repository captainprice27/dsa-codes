link : https://leetcode.com/problems/combination-sum/description/
>The time complexity of this solution is O(2^N), where N is the number of elements in the candidates array. This is because for each element in the candidates array, we have two choices - either include it in the combination or not include it. As a result, the number of recursive calls grows exponentially with the number of elements in the candidates array.

>The space complexity of this solution is O(N), where N is the number of elements in the candidates array. This is because the recursion depth can go up to N, as we are making recursive calls for each element in the candidates array. Additionally, the combination vector can store at most N elements in the worst case scenario.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> combination;

        sort(candidates.begin(),candidates.end()); 
        // Optional: sorting for potential optimization

        backtrack(candidates, target, result, combination, 0);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int target,
                   vector<vector<int>>& result, vector<int>& combination,
                   int start) 
    {
        if (target == 0) 
        {
            result.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) 
        {
            if (candidates[i] > target)
                break; // No need to continue if the candidate is greater than
                       // the target

            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination,
                      i);           // Recur with the same index
            combination.pop_back(); // Backtrack
        }
    }
};


```
