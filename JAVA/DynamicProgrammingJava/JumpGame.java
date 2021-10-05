/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

class Solution {
    public boolean canJump(int[] nums) {
        int reachable = 0;
        int len = nums.length;
        //traverse till before end of array and also till index is less then reachable
        // as if index greater than reachable it doesnt make sense to traverse and update
        for (int i = 0; i < len && i <= reachable; i++) {
            //update reachable index by prev reachable and current index+nums[i]
            reachable = Math.max(reachable, i + nums[i]);
            //if reachable is more than or equal the final len -1 then means we can reach the end
            if (reachable >= len - 1) 
                return true;   // terminate loop early to speed up
        }
        return false;

    }
}
