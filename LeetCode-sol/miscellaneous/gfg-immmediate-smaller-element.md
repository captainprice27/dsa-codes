link : https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

```cpp
class Solution{
public:	
	void immediateSmaller(vector<int>& arr, int n) 
	{
	    // Traverse the array and compare each element with the next
	    for (int i = 0; i < n - 1; ++i) 
	    {
	        if (arr[i] > arr[i + 1]) 
	        {
	            arr[i] = arr[i + 1];
	        } 
	        else 
	        {
	            arr[i] = -1;
	        }
	    }
	    // The last element has no right neighbor, so it should be set to -1
	    arr[n - 1] = -1;
	}
};
```
