
link : https://leetcode.com/problems/kth-largest-element-in-an-array/

>The time complexity of the provided solution is O(n log k), where n is the number of elements in the input vector `nums`. This is because we iterate through each of the n elements, and for each element, we perform a push operation on the priority queue, which takes O(log k) time. Since we only maintain a heap of size k, the operations remain efficient.

>The space complexity is O(k), as we are using a min-heap (priority queue) to store at most k elements. This means that the additional space used by the algorithm is proportional to the size of k, regardless of the size of the input vector.

```cpp

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Min-heap to keep track of top k largest elements
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop(); // Remove the smallest to keep size k
            }
        }

        // The top of the min-heap is the kth largest
        return pq.top();
    }
};

```
