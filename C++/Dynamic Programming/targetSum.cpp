Target Sum - LeetCode 494

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt_zero = 0,sum = 0;
        int n = nums.size();
        
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            if(nums[i]==0)
                cnt_zero ++ ;
        }
        
        if(S > sum)
            return 0;
        
        if((S+sum)%2!=0)
            return 0;
        
        int s = (S+sum)/2;
        
        int dp[n+1][s+1];
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < s+1; j++){
                if(i == 0)
                    dp[i][j] = 0;
                
                if(j == 0)
                    dp[i][j] = 1;
            }
        }       
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<s+1;j++)
            {
                if(nums[i-1]==0)
                    dp[i][j] = dp[i-1][j];
                else if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }
        }
        
        return pow(2,cnt_zero)*dp[n][s];
    }
};
