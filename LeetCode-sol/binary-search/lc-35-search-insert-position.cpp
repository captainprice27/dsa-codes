/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
**Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
**Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
 */

// link : https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int low = 0 , high = nums.size()-1;
        int ans = 0 ; // initialise
        while(low <= high)
        {
            int mid = low + (high-low)/2 ;  // to avoid overflow
            if(target > nums[high]) return high+1; // very important line to check edge cases ...
            if(nums[mid] == target)  return  mid;
              
            else if(nums[mid] > target)
            {
                ans = mid ; // now look for smaller index in right
                high = mid -1 ;
            }
            else // arr[mid] < target
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
