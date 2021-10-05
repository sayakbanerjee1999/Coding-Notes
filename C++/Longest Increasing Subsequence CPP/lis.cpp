int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        
        vector<int> dp(n, 1);
        dp[0] = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
