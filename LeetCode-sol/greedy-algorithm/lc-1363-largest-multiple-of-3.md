// link : https://leetcode.com/problems/largest-multiple-of-three/description/

``` cpp
// t.c. : O(n<10) + O(10) + O(10)
// space comp : 2*O(5) + O(10) + O(10)

class Solution {
public:
    
string largestMultipleOfThree(vector<int>& digits, string res = "") 
{
    // Arrays to help with removing digits to make sum divisible by 3
    int m1[] = {1, 4, 7, 2, 5, 8};
    int m2[] = {2, 5, 8, 1, 4, 7};
    
    // Calculate the sum of digits and count occurrences of each digit
    int sum = 0;
    int ds[10] = {};  // Array to store digit counts
    
    for (auto d : digits) 
    {
        ds[d]++;
        sum += d;
    }
    
    // Adjust the sum to make it divisible by 3
    while (sum % 3 != 0) 
    {
        bool found = false;
        // Choose the correct array based on the current sum % 3
        // if sum % 3 == 1 then auto i : m1 , else m2 ;
        for (auto i : (sum % 3 == 1 ? m1 : m2)) 
        {
            if(ds[i] != 0) 
            {
                ds[i]--; // #of digits is 1 less since we are deleting one element
                sum = (sum - i);
                found = true;
                break;
            }
        }
        
        if (!found)     // i.e. found == false
        {
            return "";// If we can't find a digit to remove, return an empty string
        }
    }
    
    // Build the result string with digits in descending order
    for (int i = 9; i >= 0; i--) // suppose all values are unique
    {
        res += string(ds[i], '0' + i); // convert it to string
    }
    
    // Handle leading zeros
    if (!res.empty() && res[0] == '0') // edge case
    {
        return "0";
    }
    
    return res;
}

};

```

> NOTE :
res += std::string(ds[i], '0' + i);       
Context: This line appears within a loop that constructs the result string res by concatenating digits in descending order.      
Explanation:       
string(ds[i], '0' + i) creates a string composed of ds[i] repetitions of the character corresponding to the digit i.         
'0' + i converts the integer i to its corresponding character representation. For example, if i is 3, '0' + i results in the character '3'.         
string(ds[i], '0' + i) creates a string of length ds[i] where each character in the string is '0' + i. For example, if i is 3 and ds[3] is 2, it creates the string "33".       
res += appends this string to the result string res.       
This effectively concatenates the digits in descending order, creating the largest possible number.      
