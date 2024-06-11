link : https://leetcode.com/problems/patching-array/description/   

## explanation

Let miss be the smallest sum in <mark>[0 , n] </mark>that we might be missing. Meaning we already know we can build all sums in **[0,miss)**. Then if we have a number num <= miss in the given array, we can add it to those smaller sums to build all sums in <mark>[0,miss+num) </mark>. If we don't, then we must add such a number to the array, and it's best to add miss itself, to maximize the reach.
*****************************
**example**    
Let's say the input is nums = [1, 2, 4, 13, 43] and n = 100. We need to ensure that all sums in the range [1,100] are possible.

Using the given numbers 1, 2 and 4, we can already build all sums from 0 to 7, i.e., the range [0,8). But we can't build the sum 8, and the next given number (13) is too large. So we insert 8 into the array. Then we can build all sums in [0,16).

Do we need to insert 16 into the array? No! We can already build the sum 3, and adding the given 13 gives us sum 16. We can also add the 13 to the other sums, extending our range to [0,29).

And so on. The given 43 is too large to help with sum 29, so we must insert 29 into our array. This extends our range to [0,58). But then the 43 becomes useful and expands our range to [0,101). At which point we're done.   

****************************
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
