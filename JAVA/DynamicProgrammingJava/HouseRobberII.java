/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [0]
Output: 0
*/

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        //base conditions
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        //call the robber I function with a basic start and end index change as
        //Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem has degenerated to the House Robber, which is already been solved.
        return Math.max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
    
    private int rob(int[] nums, int start, int end){
        //make a new array based on start and end indices and repeat HR-1
        int[] numsNew = Arrays.copyOfRange(nums, start, end + 1);
        int[] dp = new int[numsNew.length];
        if(numsNew.length == 0) return 0;
        if(numsNew.length == 1) return numsNew[0];
        dp[0] = numsNew[0];
        dp[1] = Math.max(numsNew[0], numsNew[1]);
        for(int i = 2; i < numsNew.length; i++){
            dp[i] = Math.max(dp[i - 2] + numsNew[i], dp[i - 1]);
        }
        return dp[numsNew.length - 1];
        
    }
}
