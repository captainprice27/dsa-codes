LINK: https://leetcode.com/problems/3sum-closest/

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& num, int target) {
        // vector<vector<int>> answer_grid;
        sort(num.begin(), num.end());
        int minimum_diff = INT_MAX; // initial minimum diff.
        int answer = INT_MAX; // the sum of 3 integerswhich is closest to target
        
        for (int i = 0; i < num.size(); i++) {
            // int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {
                // int sum = num[front] + num[back];
                int sum = num[i] + num[front] + num[back];

                int diff = abs(sum - target);
                if (diff < minimum_diff) // then update mindiff
                {
                    minimum_diff = diff;
                    answer = sum; // since 'sum' is closest to target
                }

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;
                else if (sum > target)
                    back--;
                else
                    return sum; // when sum == target
            }
            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;
        }
        // return answer_grid;
        return answer;
    }
};

```
