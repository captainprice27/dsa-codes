The code link : https://leetcode.com/problems/rearranging-fruits/description/  

``` cpp
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) 
    {
        unordered_map<int, int> cnt; // map used for counting freq

        for (auto c: basket1) cnt[c]++;

        for (auto c: basket2) cnt[c]--;
        //suppose say freq of 'c' in basket1 = 1 and 3 in basket2;cnt[c] = -2 (even)
        // hence after this the value of a key can be -ve as well

        vector<int> swaps ;

        for (auto &[k, v]: cnt)    // k,v --> key-value pair , here int and its frq
        {
            // if v is odd, an even distribution is never possible
            if (v % 2 != 0) return -1;

            // the count of transferred k is |v|/2
            for (int i = 0; i < abs(v) / 2; i++)
                swaps.push_back(k);
        }

        // now our final minimum cost will depend on the elements of 'last'

        // find the min of two input arrays as the intermediate

        int min_basket1 = *min_element(basket1.begin() ,basket1.end()) ;
        int min_basket2 = *min_element(basket2.begin() ,basket2.end()) ;
        
        int minx = min(min_basket1,min_basket2) ;

        // we can reduce using 3 variables as well to just one
        // int minx = min(*min_element(basket1.begin(), basket1.end()),
        //                *min_element(basket2.begin(), basket2.end()));

        // sort(last.begin(), last.end()) can be used as well
        // nth_element(last.begin(), last.begin() + last.size() / 2, last.end());
        // return accumulate(last.begin(), last.begin() + last.size() / 2, 0ll, 
        //     [&](long long s, int x) -> long long { return s + min(2*minx, x); }
        // );

        // Sort the last vector to find the smallest elements easily
        sort(swaps.begin(), swaps.end());

        long long total_cost = 0;
        int n = swaps.size() ;
        int half_size = swaps.size() / 2;

    // Calculate the minimum cost by summing up the smallest half of the last vector
        for (int i = 0; i < n/2 ; i++)   // why n/2 ? dry run !!
        {
            // Add the minimum cost of transferring the item
            total_cost += min(2 * minx, swaps[i]);
            // above is comparing direct and indirect swaps 
        }

        return total_cost;

    }
};
```
