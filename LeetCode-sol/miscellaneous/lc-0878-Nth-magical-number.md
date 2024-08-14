link : https://leetcode.com/problems/nth-magical-number/

>The time complexity of this solution is O(logN) because it uses binary search to find the nth magical number.
> The space complexity is O(1) because it only uses a constant amount of extra space regardless of the input size.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) 
    {
        long long lcm_ab = lcm(a, b); // Least common multiple of a and b
        long long left = 1, right = (long long)n * min(a, b);
        long long mod = 1e9 + 7;

        while (left < right) 
        {
            long long mid = (left + right) / 2;
            // Count how many magical numbers are <= mid
            long long count = mid / a + mid / b - mid / lcm_ab;

            if (count < n)
                left = mid + 1;
            else
                right = mid;
        }

        return left % mod;
    }

    // Function to calculate LCM
    long long lcm(long long a, long long b) 
    { 
        return a / __gcd(a, b) * b; 
    }
};

```
