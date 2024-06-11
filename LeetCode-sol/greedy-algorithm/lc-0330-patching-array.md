link : https://leetcode.com/problems/patching-array/description/   

> GREEDY : At each step, we are making the locally optimal choice (adding the smallest number that we cannot form yet) to ensure we cover as large a range as possible with each addition.
> This strategy ensures that we use the minimum number of patches since each patch significantly extends the range of numbers that can be formed.


``` cpp
/*GREEDY : At each step, we are making the locally optimal choice (adding the smallest number that we cannot form yet) to ensure we cover as large a range as possible with each addition.*/

/*This strategy ensures that we use the minimum number of patches since each patch significantly extends the range of numbers that can be formed.*/

class Solution 
{
public:
    int minPatches(vector<int>& nums, int n) 
    {
      long miss = 1, count = 0, i = 0;
      /* why miss is initialised to 1 ? since every array should have a '1' in the first element or it won't be possible to make 1*/      

      while (miss <= n) //since 'n' is the reach , miss won't cross 'n'
      {
        if (i < nums.size() && nums[i] <= miss) 
        {
            miss += nums[i++]; // making miss , which is (sum+1)
        } 
        // if loop starts from 0 -> n-1 ; but adding starts from i = 1
        // since nums[0] will always be 1 , which is already added 
        
        else // when miss is done making
        {
            miss += miss;
            count++;
        }
      }
    return count;
    }
};

```
