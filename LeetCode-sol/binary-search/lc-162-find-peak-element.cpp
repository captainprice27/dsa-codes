/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.*/

// https://leetcode.com/problems/find-peak-element/description/

class Solution 
{
public:
  int findPeakElement(vector<int>& arr) 
    {
    int n = arr.size(); //Size of array.

    // Edge cases:
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    // shrink the search space
    int low = 1, high = n - 2;
    while (low <= high) 
    {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])  return mid;
      
        // If we are in the left:
        if (arr[mid] > arr[mid - 1])   low = mid + 1;

        // If we are in the right: ,Or, arr[mid] is a common point:
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
    }
};
