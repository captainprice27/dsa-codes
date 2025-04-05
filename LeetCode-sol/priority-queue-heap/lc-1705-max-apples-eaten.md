link : https://leetcode.com/problems/maximum-number-of-eaten-apples/description/

# min-heap
>the time complexity of the `eatenApples` function can be analyzed as follows:

1. The outer loop runs while there are still apples to process or the priority queue is not empty. In the worst case, this loop can run for `n + k` iterations, where `n` is the number of days (length of the `apples` array) and `k` is the total number of apples. However, since each apple can only be processed once, the total number of iterations is effectively bounded by `O(n + k)`.

2. Inside the loop, we may push new apples into the priority queue, which takes `O(log m)` time, where `m` is the number of batches of apples in the queue. In the worst case, `m` can be at most `n`, leading to a time complexity of `O(log n)` for each push operation.

3. We also have a while loop that removes rotten apples from the priority queue. In the worst case, this could also take `O(log n)` time for each removal.

Overall, the time complexity can be approximated as `O(n log n)` due to the potential logarithmic operations for both inserting and removing elements from the priority queue.

>The space complexity of the function is determined by the priority queue. In the worst case, the priority queue can store up to `n` batches of apples (one for each day), leading to a space complexity of `O(n)`. Additionally, the space used by the input vectors `apples` and `days` is not counted towards the space complexity of the algorithm itself.

>In summary:
- Time Complexity: O(n log n)
- Space Complexity: O(n)

To solve this problem, we can use a min-heap (priority queue) to always eat the apple that is going to rot the earliest. This is a greedy approach that helps maximize the number of apples eaten.

# 🧠 Intuition & Strategy
Each day:

If the tree grows new apples, we add (expiry day, count) to the priority queue.

Before eating, remove all apple batches that are already rotten or have 0 apples left.

If there’s any fresh apple batch, eat 1 apple from the batch with the earliest expiry date.

We continue doing this even after the last input day, as long as apples remain in the heap.
```cpp
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size(), i = 0, eaten = 0;
        // Priority queue storing pairs (expiry_day, count_of_apples)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        while (i < n || !pq.empty()) {
            // If today we have new apples, push them with expiry date
            if (i < n && apples[i] > 0) {
                pq.push({i + days[i], apples[i]});
            }

            // Remove rotten apples or empty batches
            while (!pq.empty() && (pq.top().first <= i || pq.top().second == 0)) {
                pq.pop();
            }

            // Eat one apple from the batch with the earliest expiry
            if (!pq.empty()) {
                auto [expire, count] = pq.top();
                pq.pop();
                eaten++;
                if (count > 1) {
                    pq.push({expire, count - 1});
                }
            }
            i++;
        }

        return eaten;
    }
};

```

# 🔥 Greedy Insight
By always eating the apple that rots first, we prevent early expiry and maximize total consumption. This is similar to Earliest Deadline First (EDF) scheduling used in real-time systems.

Let me know if you want a visual simulation or a version without using a priority queue.
