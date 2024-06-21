link : https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

```cpp
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {
        // from the beginnning or end , not from middle
        int left_sum = 0 , right_sum = 0, max_sum = 0 ;
        int n = cardPoints.size();
        for(int i=0;i<k;i++)
        {
            left_sum += cardPoints[i];
            max_sum = left_sum ; 
        }
        int right_index = n-1 ;
        for(int i = k-1 ; i>=0;i--)
        {
            left_sum = left_sum - cardPoints[i];
            right_sum += cardPoints[right_index];
            right_index--;

            max_sum = max(max_sum , left_sum + right_sum);
        }

        return max_sum ; 
    }
};
```
