// problem link : https://leetcode.com/problems/subsets/description/

// best solution ever : https://leetcode.com/problems/subsets/solutions/27278/c-recursive-iterative-bit-manipulation/

// iterative sol is a piece of art ...   
```cpp
//bit MANIPULATION
/ bit manipulation approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> subs(p);
        for (int i = 0; i < p; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if ((i >> j) & 1) 
                {
                    subs[i].push_back(nums[j]);
                }
            }
        }
        return subs;
    }
};
```
