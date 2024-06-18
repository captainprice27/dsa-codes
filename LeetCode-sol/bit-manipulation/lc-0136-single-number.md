link : https://leetcode.com/problems/single-number/description/    
TIME COMPLEXITY : O(N) , SPACE O(1)

```cpp
// bit manipulation ...
// T.C. --> O(N) , S.C. --> O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {   int ans = 0 ;
        for(auto& element : nums)
            ans ^= element; 
        return ans;  
    }
};

```
