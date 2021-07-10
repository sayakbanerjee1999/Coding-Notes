class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        
        int n = prices.size();
        
        int dp[k+1][n];
        
        for(int i = 0; i < k+1; i++){
            for(int j = 0; j < n; j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < k+1; i++){
            for(int j = 1; j < n; j++){
                int maxProfit = dp[i][j-1];
                
                for(int k = 0; k < j; k++){
                    int ptilltm1 = dp[i-1][k];              // Profit till t-1 transactions
                    int pro = prices[j] - prices[k];        // Profit between day j and each day k
                    
                    maxProfit = max(maxProfit, (ptilltm1 + pro));
                }
                
                dp[i][j] = maxProfit;
            }
        }
        
        return dp[k][n-1];
    }
};
