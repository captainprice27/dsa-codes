link : https://leetcode.com/problems/subsets-ii/description/    

```cpp

```

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p = 1 << n;
        unordered_set<string> seen;
        vector<vector<int>> ans;

        for (int i = 0; i < p; i++) 
        {
            vector<int> subset;
            string hashKey;
            for (int j = 0; j < n; j++) 
            {
                if ((i >> j) & 1) 
                {
                    subset.push_back(nums[j]);
                    hashKey += to_string(nums[j]) + "#";
                }
            }
            if (seen.find(hashKey) == seen.end()) 
            {
                ans.push_back(subset);
                seen.insert(hashKey);
            }
        }

        return ans;
    }
};
```
