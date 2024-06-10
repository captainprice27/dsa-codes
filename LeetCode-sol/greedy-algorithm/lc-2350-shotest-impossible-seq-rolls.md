
link : https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/

``` cpp
class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) 
    {
        unordered_set<int> unique_numbers;

        int sequence_length = 0;
        
        for (int roll : rolls) 
        {
            unique_numbers.insert(roll);
            
            if (unique_numbers.size() == k) //i.e. all unique numbers
            {
                // We have formed a complete sequence of length 'sequenceLength + 1'
                sequence_length++;
                unique_numbers.clear();  // Reset the set for the next sequence
            }
        }
        
        // The shortest sequence that cannot be formed is one more than the number of full sequences
        return (sequence_length + 1) ;
    }
};
```
