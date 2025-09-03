class Solution:
    def knapsack(self, W, val, wt):
        # code here
        n = len(wt)
        dp = [[0 for j in range(W+1)] for i in range(n+1)]
        
        # Initialize (Base Conditions)
        # If j == 0 (i.e., W (subproblem) = 0) Profit is 0
        # If i == 0 (i.e., no wt array is provided (subproblem) -> so again Profit is 0)
        
        for i in range(1, n+1):
            for j in range(1, W+1):
                # Choice Diagram.
                # Always remember i-1 maps to the val/wt array (i=1, i-1 = 0th index of wt, val array)
                # If w <= W [j] index. Then you have 2 choices.
                # Take -> If you take you make a call on (n-1) index with reduced weight W - w
                # Do not Take -> You make a call on n-1 index with same weight W
                if wt[i-1] <= j:            # j is the subproblem on weight
                    dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]],     # Take
                                    dp[i-1][j])  #Not Take (Not adding to profit)
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[n][W]
                    
                    
