link : https://leetcode.com/problems/next-greater-element-iii/description/

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int nextGreaterElement(int n) 
    {
        string num = to_string(n);
        int len = num.length();
        
        // Step 1: Find the first digit that is 
        //smaller than the digit next to it
        int i = len - 2;
        while (i >= 0 && num[i] >= num[i + 1]) 
        {
            i--;
        }
        
        // If no such digit is found, 
        //the number is in descending order, return -1
        if (i < 0) return -1;
        
        // Step 2: Find the smallest digit on the 
        //right side of (i'th digit) which is larger than num[i]
        int j = len - 1;
        while (j > i && num[j] <= num[i]) 
        {
            j--;
        }
        
        // Step 3: Swap digits at i and j
        swap(num[i], num[j]);
        
        // Step 4: Reverse the digits after index i
        reverse(num.begin() + i + 1, num.end());
        
        // Step 5: Convert back to integer and 
        // check if it is within the 32-bit integer range
        long long nextGreater = stoll(num);
        if (nextGreater > INT_MAX) return -1;
        
        return nextGreater;
    }
};

```
