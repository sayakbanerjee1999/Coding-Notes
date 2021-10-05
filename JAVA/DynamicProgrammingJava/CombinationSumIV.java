/*
Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
*/

public class Solution{
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        Arrays.fill(dp, -1);
        return combinationSum4(nums, target, dp, 0);
    }

    private int combinationSum4(int[] nums, int target, int[] dp, int sum) {
        if (sum > target)
            return 0;
        if (sum == target)
            return 1;
        if (dp[sum] != -1)
            return dp[sum];
        var count = 0;
        for (int num : nums)
            count += combinationSum4(nums, target, dp, sum + num);
        dp[sum] = count;
        return dp[sum];
    }
}
