// link : https://leetcode.com/problems/most-profit-assigning-work/description/    

```cpp
// a single job can be assigned to multiple workers
// but a worker can get  only one job at most
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,vector<int>& worker)
    {
        vector<pair<int, int>> jobs;
        int n = profit.size(), res = 0, i = 0, best = 0;

        for (int j = 0; j < n ; j++)
        {
            jobs.push_back(make_pair(difficulty[j], profit[j]));
        } 
        // sort jobs based on difficulty   
        sort(jobs.begin(), jobs.end());
        // sort worker wrt working ability
        sort(worker.begin(), worker.end());

        for (auto& ability : worker) 
        {
            while (i < n && ability >= jobs[i].first)
                {
                    best = max(jobs[i++].second, best);
                    // jobs[i].second --> profit
                    /// note that jobs[i++] not jobs[i]
                }
            res += best;
        }
        return res;
    }
};

```
