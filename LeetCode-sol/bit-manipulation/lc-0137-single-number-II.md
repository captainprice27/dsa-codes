link : https://leetcode.com/problems/single-number-ii/description/    
## NORMAL APPROACH USING MAP

```cpp
// freq map (not bit manipulation)
// t.c. --> O(n) + O(n) , space -->
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        // n = nums.size()
        for (auto& it : nums) {
            freq[it]++; // frequency map
        }
        for (auto& entry : freq) {
            if (entry.second == 1)
                return entry.first;
        }
        return -1;
    }
};
```


## USING BIT MANIPULATION 

```cpp
// USING BIT MANIPULATION
// num >> i --> i'th bit of 'num'
// (num >>i)&1 --> extracting i'th bit of num

#define fr(a,b) for(int i=a;i<b;++i)
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans = 0 ;
        // for a particular bit position , we are checking nums
        // 0 -->31 possible bits in integer 
        fr(0,32)
        {
            int sum = 0 ; // sum of bits
            // now for a particular bit position say 'i', we'll check
            // every number in array
            for(auto& number : nums)
            {
                sum += ((number >> i) & 1);
            }
            sum = sum%3 ;
            ans = ans | (sum << i) ;
        }

        return ans; 
    }
};
```
