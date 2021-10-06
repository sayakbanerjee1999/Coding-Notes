Partition Equal Subset Sum - LeetCode 416

class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum){
        int n = nums.size();
        bool dp[n+1][sum+1];
        
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(i == 0)
                    dp[i][j] = false;
                
                if(j == 0)
                    dp[i][j] = true;
            }
        }
        
        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < sum+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
    
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        long long int sum = 0;
        for(int i = 0; i < size; i++)
            sum += nums[i];
        
        long long int target = sum/2;
        
        if(sum%2 != 0)
            return false;
        
        else
            return subsetSum(nums, target);
    }
};
