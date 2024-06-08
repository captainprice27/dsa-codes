THERE ARE TWO  APPROACHES FOR THE CODE 
LINK : https://leetcode.com/problems/candy

## FIRST SOLUTION

``` cpp   
// two pass greedy approach
// time --> O(2N) , space O(N)
// this  is NOT the ultimate optimal solution ... which is slope approach 

class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int> candies(n, 1); // initialising with 1 candy each chldrn

        // 1st pass of the ratings array --> LEFT PASS
        // index '0' is omitted cuz 'i-1' wil make it index '-1'
        // O(N) time
        for (int i = 1; i < n; i++) // if equal or smaller , ignore
        {
            if (ratings[i] > ratings[i - 1]) 
                candies[i] = candies[i - 1] + 1;
        }

        // 2nd pass of the ratings array --> RIGHT PASS
        //'n-1' is omitted since 'i+1' will make it index 'n'(doesn't exist) 
        // another O(N) time
        for (int i = n - 2; i >= 0; i--) // if equal or smaller ignore
        {
            if (ratings[i] > ratings[i + 1])
            {   
                // candies[i] = candies[i+1] + 1 ;
                // then max of left pass i and right pass i 
                // left pass value at index i --> candies[i]
                // right pass value at index i --> candies[i+1] +1;
                candies[i] = max(candies[i], candies[i + 1] + 1);  
            }          
        }

        int minimum_total_candies = 0;
        // now iterating values in the candies vector
        for (int candy : candies) 
        {
            minimum_total_candies += candy;
        }
        return minimum_total_candies;
    }
};
```


But this is also nnot the very suitable and most optimal solution . 
Te most optimal solution takes O(1) space . which is the     
<span style="font-family:Papyrus; font-size:21em;"> **SLOPE APPROACH**  </span>.
*************************************************************************************************************************************
## slope approach 

``` cpp 


// SLOPE APPROACH O(1) SPACE COMPLEXITY

class Solution 
{
public:
    int candy(vector<int>& ratings) {

        int n = ratings.size();

        int candy = n, i = 1;
        while(i<n)
        {
            if(ratings[i] == ratings[i-1])  // flat surface
            {
                i++;
                continue;
            }
            
            //For increasing slope
            int peak = 0;
            while(ratings[i] > ratings [i-1])
            {
                peak++;
                candy += peak;
                i++;
                // edge case , if only increasing slope in array 
                if(i == n) return candy;
            }
            
            //For decreasing slope
            int valley = 0;
            while(i<n && ratings[i] < ratings[i-1])
            {
                valley++;
                candy += valley;
                i++;
            }
            // now we have added the peak value twice in the candy value
            // we need to add only max(val1,val2)
            // val1 --> peak(say) , val2 --> peak from other side/valley(say)
            candy = candy - min(peak, valley); //Keep only the higher peak
        }
        return candy;
    }
};
```

