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
EXPLANATION:   
Explanation
Initialization:

n is the size of the input vector nums.
p is calculated as 1 << n, which is 2^n. This represents the total number of subsets for a set of size n. For example, if n = 3, p = 8, meaning there are 8 possible subsets.
subs is a vector of vectors of integers with size p, initialized to hold all the subsets.
Outer Loop (for (int i = 0; i < p; i++)):

This loop iterates over each possible subset. The variable i serves as a bitmask representing the inclusion or exclusion of each element in the subset. Each bit in i corresponds to an element in nums.
Inner Loop (for (int j = 0; j < n; j++)):

This loop checks each bit of the bitmask i to determine whether the corresponding element in nums should be included in the current subset.
Bitwise Operation 
## **(if ((i >> j) & 1)):**

**(i >> j) & 1** checks **if the j-th bit of i is set to 1**. If it is, this means the j-th element in nums should be included in the current subset.
i >> j shifts the bits of i to the right by j positions.
& 1 checks if the least significant bit of the shifted value is 1.     
## Both (i >> j) & 1 and (1 << j) & i are used to check if the j-th bit of i is set to 1. They are logically equivalent:
Subset Construction:

If the condition (i >> j) & 1 is true, nums[j] is added to the current subset subs[i].
Return Result:

After both loops complete, subs contains all possible subsets of nums, and it is returned as the final result.
Example Walkthrough
Let's walk through an example where nums = {1, 2, 3}:

n = 3, so p = 8 (i.e., there are 8 possible subsets).
The outer loop runs from i = 0 to i = 7 (inclusive).
Each value of i represents a subset:

i = 0 (binary 000): No elements are included. Subset is [].
i = 1 (binary 001): Only the first element is included. Subset is [1].
i = 2 (binary 010): Only the second element is included. Subset is [2].
i = 3 (binary 011): First and second elements are included. Subset is [1, 2].
i = 4 (binary 100): Only the third element is included. Subset is [3].
i = 5 (binary 101): First and third elements are included. Subset is [1, 3].
i = 6 (binary 110): Second and third elements are included. Subset is [2, 3].
i = 7 (binary 111): All elements are included. Subset is [1, 2, 3].
This bit manipulation approach efficiently generates all subsets by interpreting each possible value of i as a binary mask indicating which elements to include in the subset.
