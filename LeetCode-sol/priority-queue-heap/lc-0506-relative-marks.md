https://leetcode.com/problems/relative-ranks/description/

>The time complexity of the provided solution is O(n log n). This is primarily due to the use of a priority queue (max-heap) to store the scores along with their indices. Inserting each of the n scores into the priority queue takes O(log n) time, resulting in a total of O(n log n) for the insertion phase. Additionally, extracting elements from the priority queue also takes O(log n) time for each of the n elements, but since we are already counting the insertion time, the overall time complexity remains O(n log n).

>The space complexity is O(n) because we are storing the scores in the priority queue, which can hold up to n elements. Additionally, we are using a result vector of size n to store the final ranks. Therefore, the overall space complexity is O(n).

```cpp
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        // Max-heap to store <score, index> pairs
        priority_queue<pair<int, int>> pq;

        // Push all scores with their indices into the heap
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }

        vector<string> result(n);
        int rank = 1;

        // Extract elements from the heap and assign ranks
        while (!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();

            if (rank == 1)
                result[idx] = "Gold Medal";
            else if (rank == 2)
                result[idx] = "Silver Medal";
            else if (rank == 3)
                result[idx] = "Bronze Medal";
            else
                result[idx] = to_string(rank);

            rank++;
        }

        return result;
    }
};

```
