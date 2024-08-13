link : https://leetcode.com/problems/permutations/

> The time complexity of this solution is O(N!), where N is the number of elements in the input vector. This is because there are N! possible permutations of the elements in the input vector, and we are generating all of them.

>The space complexity is also O(N!), as we are storing all possible permutations in the result vector.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }

private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) 
        {
            result.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) 
        {
            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, result);
            swap(nums[start], nums[i]); // backtrack
        }
    }
};


```


### uaing 'next_permutation'
> The time complexity of this solution is O(n!), where n is the number of elements in the input vector. This is because there are n! possible permutations of the elements in the vector, and we are generating all of them.

>The space complexity is also O(n!), as we are storing all possible permutations in the result vector.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        
        do 
        {
            result.push_back(nums);
        } 
        
        while (next_permutation(nums.begin(), nums.end()));

        return result;
    }
};


```
