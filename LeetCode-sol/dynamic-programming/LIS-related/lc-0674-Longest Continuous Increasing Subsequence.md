https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/

![image](https://github.com/user-attachments/assets/1bdbbf7e-172a-4aa9-a4bb-d871f3411d74)


```cpp
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        if (nums.empty()) return 0;

        int maxlen = 1 ; 
        int curlen = 1 ; 
        for(int i=0;i <nums.size()-1;i++)
        {   
            // int curlen = 1 ; 
            if(nums[i+1] > nums[i])
            {
                curlen++ ; 
                maxlen = max(maxlen,curlen) ;
            }
           // maxlen = max(maxlen,curlen) ; 
           else curlen = 1 ; 
        }
        return maxlen ; 
    }
};
```
