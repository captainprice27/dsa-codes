link : https://leetcode.com/problems/gas-station/

``` cpp
// unique sol gurunteed

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
        int surplas = 0 ; // gas - cost for a single iteration
        int total_surplas = 0 ;

        int start = 0; // starting index
        for(int i=0;i<n;i++)
        {
            // if((gas[i]-cost[i]) >=0)    --> this sol won't work think about testcase gas[]=5,1,2,3,4 ; cost[]=4,4,1,5,3
            // {
            //     start = i ;
            //     break;
            // }
            surplas += gas[i] - cost[i] ;
            if(surplas < 0 )    
            {
                surplas = 0 ; // reset
                start = i+1 ;  // update start
            }
        }

        for(int i=0;i<n;i++)
        {
            total_surplas += gas[i]-cost[i];
        }

        if(total_surplas < 0)   return -1 ;
        return start;
    }
};

```
