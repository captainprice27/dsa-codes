
link : https://www.geeksforgeeks.org/problems/number-of-nges-to-the-right/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-nges-to-the-right
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> count_NGE(int n, vector<int> &arr, 
                        int queries, vector<int> &indices) 
    {
        vector<int> result(queries);
        
        // For each query, calculate the count of greater elements to the right
        for (int q = 0; q < queries; q++) 
        {
            int index = indices[q];
            int count = 0;
            
            for (int j = index + 1; j < n; ++j) 
            {
                if (arr[j] > arr[index]) 
                {
                    count++;
                }
            }
            result[q] = count;
        }
        
        return result;
    }
};

```
