link : https://leetcode.com/problems/subarrays-with-k-different-integers/description/

```cpp
class Solution {
public:
    int helper(vector<int>& nums, int k) {
        int left = 0, right = 0;
        map<int,int> map;
        int cnt = 0;

        while(right < nums.size()) // O(n) time
        {
            map[nums[right]]++;
            // maps.size() --> different elements in the map
            while(map.size() > k) 
            {
                map[nums[left]]--; //erasing elment  pointed by left

                if(map[nums[left]] == 0)  // after erasing if freq cnt is 0
                    {
                      map.erase(nums[left]); // the element is no longer in map
                    }

                left++;
            }
            
            cnt = cnt + (right - left + 1); // # extra sub_arrs adding 
            right++;
        }

        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};
```
