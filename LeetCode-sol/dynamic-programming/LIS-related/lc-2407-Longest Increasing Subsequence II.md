link : https://leetcode.com/problems/longest-increasing-subsequence-ii/description/

SEGMENT TREE

```cpp
class Solution {
private:
    vector<int> tree;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = 0;
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = max(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) return 0;
        if (l <= start && r >= end) return tree[node];
        int mid = (start + end) / 2;
        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);
        return max(left, right);
    }

public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());
        int size = maxVal + 1; // Segment tree size
        tree.resize(4 * size); // 4 * size for segment tree
        build(1, 1, maxVal);

        int maxLength = 1;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            int l = max(1, curr - k); // Ensure range starts at 1
            int r = curr - 1;
            int prevMax = (r < l) ? 0 : query(1, 1, maxVal, l, r);
            int len = prevMax + 1;
            update(1, 1, maxVal, curr, len);
            maxLength = max(maxLength, len);
        }

        return maxLength;
    }
};
```
