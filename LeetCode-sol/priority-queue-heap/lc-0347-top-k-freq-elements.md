https://leetcode.com/problems/top-k-frequent-elements/description/   
SIMILAR : https://leetcode.com/problems/top-k-frequent-words/description/

> BETTER SOLUTION IS WITH BUCKET SORT WHICH IS BELOW

> Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
> The time complexity of the provided solution is O(n), where n is the number of elements in the input vector `nums`. This is because we perform a single pass through the `nums` array to count the frequency of each element (Step 1), and then we iterate through the frequency map to populate the buckets (Step 2). Finally, we collect the top k frequent elements from the buckets (Step 3), which in the worst case can also take O(n) time if all elements have the same frequency. However, since we are only interested in the top k elements, this part is effectively limited to O(k) in practice.

>The space complexity is O(n) as well, primarily due to the storage of the frequency map and the buckets. The frequency map can store up to n unique elements in the worst case, and the buckets array has a size of n + 1 to accommodate all possible frequencies from 0 to n. Therefore, the overall space complexity is O(n). 

>In summary, both the time and space complexity of the solution are O(n).
```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each element
        for (int num : nums) {
            freq[num]++;
        }

        int n = nums.size();
        // Step 2: Create buckets where index = frequency
        vector<vector<int>> buckets(n + 1);
        for (auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }

        // Step 3: Collect k most frequent from highest freq to lowest
        vector<int> result;
        for (int i = n; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k)
                    break;
            }
        }

        return result;
    }
};

```

# USING PRIORITY QUEUE

>The time complexity of the provided solution can be analyzed as follows:

1. Counting frequencies: This step involves iterating through the `nums` array, which has a time complexity of O(n), where n is the number of elements in `nums`.

2. Building the min-heap: In this step, we iterate through the frequency map, which contains at most n unique elements (in the worst case). For each unique element, we perform a push operation on the priority queue. The push operation takes O(log k) time, and since we may push up to n elements, this results in a time complexity of O(n log k).

3. Extracting elements from the heap: This involves popping k elements from the priority queue, which takes O(k log k) time.

>Combining these steps, the overall time complexity is O(n + n log k + k log k). In the case where k is much smaller than n, this simplifies to O(n log k).

>The space complexity of the solution is determined by the storage used for the frequency map and the priority queue. The frequency map can store up to n unique elements, leading to a space complexity of O(n). The priority queue, which stores at most k elements, contributes O(k) space. Therefore, the overall space complexity is O(n) in the worst case, assuming n is larger than k.

>In summary, the time complexity is O(n log k) and the space complexity is O(n).

```cpp
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Use a min-heap to keep top k elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto& [num, count] : freq) {
            pq.push({count, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Step 3: Extract elements from heap
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
```
