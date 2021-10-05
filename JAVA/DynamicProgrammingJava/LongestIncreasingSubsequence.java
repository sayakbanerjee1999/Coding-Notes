class Solution {
    public int lengthOfLIS(int[] nums) {
        if (nums.length==0)
            return 0;
        int[] dp = new int[nums.length];
        //LIS at first element will have length 1 base case
        dp[0] = 1;
        //final result
        int maxLen = 1;
        for (int i=1;i<dp.length;i++){
            //length of LIS ending at index i
            int currLen = 0;
            //consider and compare with elements before curr
            for (int j=0;j<i;j++){
                //valid if curr>previous
                if (nums[i]>nums[j]){
                    currLen = Math.max(currLen, dp[j]);
                }
            }
            //store result in dp
            dp[i] = currLen+1;
            maxLen = Math.max(maxLen, dp[i]);
        }
        return maxLen;
    }
}
