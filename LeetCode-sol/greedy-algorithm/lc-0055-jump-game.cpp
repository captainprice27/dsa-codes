// https://leetcode.com/problems/jump-game

/* You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position . Return true if you can reach the last index, or false otherwise. */


class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        int i, minjump = 0;
        for(i = nums.size()-2; i >= 0; i--)
        {
            minjump++;
            if(nums[i] >= minjump)
			    minjump = 0;
        }
         return minjump == 0 ;
    }
};
