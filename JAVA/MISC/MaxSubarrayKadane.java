
class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;
        int sum = nums[0];
        int maxsum = nums[0];
        for(int i=1;i<n;i++){
            sum = Math.max(nums[i],sum+nums[i]);
            maxsum = Math.max(maxsum,sum);
        }
        return maxsum;
    }
}
