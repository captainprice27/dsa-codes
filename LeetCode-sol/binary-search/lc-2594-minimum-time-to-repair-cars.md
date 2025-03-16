https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16

>The time complexity of the given solution is O(n log m), where n is the number of ranks (the size of the input vector) and m is the maximum possible time required to repair the cars. The binary search runs in O(log m) time, and for each iteration of the binary search, we iterate through the ranks to calculate the total number of cars that can be repaired, which takes O(n) time. Thus, the overall time complexity is O(n log m).

>The space complexity is O(1) because we are using a constant amount of extra space regardless of the input size. The variables used (left, right, mid, totalCars) do not depend on the size of the input vector. Therefore, the space complexity is constant.

```cpp
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0;
        long long right = 1e14; 
        // Reasonable upper bound based on constraints

        while (left < right) 
        {
            long long mid = left + (right - left) / 2;
            long long totalCars = 0;

            // Calculate total cars that can be repaired in time mid
            for (int rank : ranks) 
            {
                // n^2 <= mid / rank ---> n <= sqrt(mid / rank)
                totalCars += (long long)sqrt(mid / (double)rank);
            }

            if (totalCars >= cars) 
            {
                right = mid; // Try a smaller time
            } 
            else 
            {
                left = mid + 1; // Try a larger time
            }
        }

        return left;
    }
};
```
