/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.*/

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;
// ********************************************************************************************
int search(vector<int>& arr,int k) 
{    
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) 
        {
            if (arr[low] <= k && k <= arr[mid]) 
            {
                //element exists:
                high = mid - 1;
            }
            else 
            {
                //element does not exist:
                low = mid + 1;
            }
        }
          
        else 
        { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) 
            {
                //element exists:
                low = mid + 1;
            }
            else 
            {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}

// ******************************************************************************************

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = 9, k = 1;
    int ans = search(arr, n, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
