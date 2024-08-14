link : https://leetcode.com/problems/find-k-closest-elements/description/

>The time complexity of this solution is O(log(n) + k), where n is the size of the input array arr. This is because we use binary search to find the closest element to x, which takes O(log(n)) time. Then, we iterate through the subarray of k closest elements, which takes O(k) time.

>The space complexity is O(k) because we store the k closest elements in a vector before returning it.

>Overall, this solution is efficient in terms of time complexity as it utilizes binary search to find the closest element to x and then returns the k closest elements in linear time.

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        int left = 0, right = arr.size() - 1;
        
        // Binary search to find the closest element to x
        while (right - left >= k) 
        {
            if (abs(arr[left] - x) > abs(arr[right] - x)) 
            {
                left++;
            } 
            else 
            {
                right--;
            }
        }        
        // The subarray arr[left:right+1] contains the k closest elements
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
    }
};


```
