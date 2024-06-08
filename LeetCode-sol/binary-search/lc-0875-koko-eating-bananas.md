Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

link: https://leetcode.com/problems/koko-eating-bananas/description/


``` cpp
class Solution 
{
public:

    // this helper funtion will help us to find out the total number 
    // of hours we need to finish for a particular 'k' banana/hour rate
    long long getHoursToEatAll(vector<int>&piles, int bananasPerHour)
    {
        long long totalHours = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            int hoursToEatPile = ceil(piles[i] / (double)bananasPerHour);  // double is used to swiftly divide to double to gget its real ceil
          // if we did not use double , then ceil can't be calculated , it would be floor by default
            // above is to calculate total hours to complete one pile ...
            totalHours += hoursToEatPile; // updating total time to finish all
        }
        return totalHours;
    }

// this is primary function 
//************************************************************************************
    int minEatingSpeed(vector<int>& piles, int targetHours)
    {
        int low = 1, high = *(max_element(piles.begin(), piles.end()));  // * is used to dereference the iterator
        int ans = -1;
      
        while(low <= high)
        {
            int mid = low + (high - low) / 2; // trick to avoid overflow...
            long long hoursToEatAll = getHoursToEatAll(piles, mid);
            
            if (hoursToEatAll <= targetHours)
            {
                ans = mid; //record the answer (this is the best we could record till curr step)
                // then we can get even minimum so trim down the search space 
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
```
