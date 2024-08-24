link : https://leetcode.com/problems/find-the-closest-palindrome/description/  

>The time complexity of this solution is O(logn) where n is the input number, as we are converting the input number to a long long integer.
>The space complexity is O(1) as we are using a constant amount of extra space regardless of the input size.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) 
    {
        int len = n.size();
        //
        long long num = stoll(n);
        //
        set<long long> candidates;

        // Edge case handling: Small numbers and 10^x or 10^x - 1
        candidates.insert((long long)pow(10, len) + 1);
        candidates.insert((long long)pow(10, len - 1) - 1);

        // Create prefix
        long long prefix = stoll(n.substr(0, (len + 1) / 2));

        // Generate potential palindrome candidates
        for (int i = -1; i <= 1; i++) 
        {
            string candidate = to_string(prefix + i);
            string rev = string(candidate.rbegin(), candidate.rend());
            if (len % 2 == 0) 
            {
                candidates.insert(stoll(candidate + rev));
            } 
            else 
            {
                candidates.insert(stoll(candidate + rev.substr(1)));
            }
        }

        // Remove the original number itself
        candidates.erase(num);

        // Find the closest palindrome
        long long closest = -1;
        for (long long candidate : candidates) 
        {
            if (closest == -1 || abs(candidate - num) < abs(closest - num) ||
                (abs(candidate - num) == abs(closest - num) &&
                 candidate < closest)) 
            {
                closest = candidate;
            }
        }

        return to_string(closest);
    }
};

```
