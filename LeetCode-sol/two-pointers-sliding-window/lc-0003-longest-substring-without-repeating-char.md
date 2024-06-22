// link : https://leetcode.com/problems/longest-substring-without-repeating-characters

```cpp
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1); // Initialize to -1 indicating not visited
        int left = 0, right = 0; // Initialize pointers
        int max_length = 0;
        int n = s.size();

        while (right < n) {
            if (map[s[right]] != -1) { // If the character is visited
                // Move left to the right of the last occurrence of s[right]
                left = max(left, map[s[right]] + 1);
            }

            // Update the map with the current index of the character
            map[s[right]] = right;

            // Calculate the length of the current substring
            max_length = max(max_length, right - left + 1);
            right++; // Move the right pointer
        }

        return max_length;
    }
};

```
