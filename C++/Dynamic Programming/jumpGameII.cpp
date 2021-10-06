Jump Game II - LeetCode 45
  
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX - 1);
        dp[n - 1] = 0;
        
        for (int curr = n - 2; curr >= 0; curr--) {            
            for (int i = 0; curr + i < n && i <= nums[curr]; i++) {
                dp[curr] = min(dp[curr] , 1 + dp[curr + i]);
            }
        }
        
        return dp[0];
    }
};
