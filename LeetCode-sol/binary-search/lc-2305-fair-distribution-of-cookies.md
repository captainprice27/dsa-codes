
link : https://leetcode.com/problems/fair-distribution-of-cookies/description/
PROBLEM IS SIMILAR TO THE SPLIT ARRAY LARGEST SUM , WITH ONE MODIFICATION THAT THE ELEMENTS MAY NOT BE CONTIGUOUS ...


```cpp

#include <vector>
#include <algorithm> // for max_element
#include <numeric>   // for accumulate
using namespace std;

class Solution {
public:
    // Backtracking function to check if cookies can be distributed to k children with max sum <= target
    bool canDistribute(vector<int>& cookies, vector<int>& childrenSums, int pos, int k, int target) {
        int n = cookies.size();
        // Base case: all cookies assigned successfully
        if (pos == n) {
            return true;
        }
        
        // Try assigning the current cookie to each child
        for (int i = 0; i < k; i++) {
            // If adding this cookie doesn't exceed target, try it
            if (childrenSums[i] + cookies[pos] <= target) {
                childrenSums[i] += cookies[pos];
                if (canDistribute(cookies, childrenSums, pos + 1, k, target)) {
                    return true;
                }
                childrenSums[i] -= cookies[pos]; // Backtrack
            }
            // Optimization: If this child has 0 cookies, further children will also fail (symmetry)
            if (childrenSums[i] == 0) {
                break;
            }
        }
        return false;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int low = *max_element(cookies.begin(), cookies.end()); // Minimum possible unfairness
        int high = accumulate(cookies.begin(), cookies.end(), 0); // Maximum possible unfairness
        
        // Binary search for the minimum unfairness
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Track sum of cookies for each child
            vector<int> childrenSums(k, 0);
            
            // Check if we can distribute with max sum <= mid
            if (canDistribute(cookies, childrenSums, 0, k, mid)) {
                high = mid - 1; // Try a smaller unfairness
            } else {
                low = mid + 1;  // Increase the unfairness
            }
        }
        
        return low; // Minimum unfairness
    }
};
```


The time and space complexity analysis for the provided code can be summarized as follows:

**Time Complexity:**
The time complexity of the `canDistribute` function is primarily determined by the number of ways to distribute cookies among children. In the worst case, each cookie can be assigned to any of the `k` children, leading to a branching factor of `k` for each cookie. Therefore, the time complexity can be expressed as O(k^n), where `n` is the number of cookies. This exponential complexity arises because for each cookie, we explore all possible distributions among the children.

However, the optimization that stops further exploration when a child has 0 cookies can reduce the number of recursive calls in practice, especially when `k` is large relative to `n`. Still, in the worst-case scenario, the complexity remains exponential.

**Space Complexity:**
The space complexity is determined by the recursion stack used during the backtracking process. In the worst case, the maximum depth of the recursion can go up to `n`, which is the number of cookies. Additionally, we use a vector `childrenSums` of size `k` to keep track of the sum of cookies assigned to each child. Thus, the space complexity can be expressed as O(n + k), where O(n) is for the recursion stack and O(k) is for the `childrenSums` vector.

In summary:
- Time Complexity: O(k^n)
- Space Complexity: O(n + k)
