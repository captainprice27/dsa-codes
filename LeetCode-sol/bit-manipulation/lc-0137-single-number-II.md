link : https://leetcode.com/problems/single-number-ii/description/    

> NORMAL APPROACH USING MAP

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
