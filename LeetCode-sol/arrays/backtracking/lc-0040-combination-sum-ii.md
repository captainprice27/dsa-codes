link : https://leetcode.com/problems/combination-sum-ii

### brute force 

> The time complexity of this solution is O(2^n * n) where n is the number of candidates. This is because we are generating all possible subsets of the candidates using a bitmask approach, which results in 2^n subsets. For each subset, we iterate through the candidates array to calculate the sum, which takes O(n) time.

>The space complexity is O(2^n * n) as well, as we are storing all the subsets that sum up to the target in the result vector. Each subset can have at most n elements, so the total space complexity is O(2^n * n)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates

        for (int i = 1; i < (1 << n); ++i) { // Generate all subsets
            vector<int> subset;
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(candidates[j]);
                    sum += candidates[j];
                }
            }
            if (sum == target) {
                result.push_back(subset);
            }
        }

        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()),
                     result.end()); // Remove duplicates

        return result;
    }
};

```


### backtracking APRROACH

>The time complexity of this solution is O(2^n) where n is the number of elements in the candidates array. This is because for each element in the candidates array, we have two choices - either include it in the combination or not include it. This results in a binary tree of recursive calls with a maximum of 2^n leaf nodes.

>The space complexity of this solution is O(n) where n is the number of elements in the candidates array. This is because we are using recursion to generate all possible combinations, and the recursion stack will have a maximum depth of n. Additionally, the space complexity also includes the space used for the result vector and the combination vector.

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
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
            if (i > start && candidates[i] == candidates[i - 1])
                continue; // Skip duplicates
            if (candidates[i] > target)
                break;

            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], result, combination,
                      i + 1);       // Move to the next index
            combination.pop_back(); // Backtrack
        }
    }
};
 
```
