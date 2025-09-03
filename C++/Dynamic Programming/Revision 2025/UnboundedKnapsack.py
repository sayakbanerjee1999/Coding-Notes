#User function Template for python3

class Solution:
    def knapSack(self, val, wt,capacity):
        # code here
        n = len(wt)
        dp = [[0 for j in range(capacity+1)] for i in range(n+1)]
        
        # Base Condition
        # i == 0 (wt array is empty). So Profit is 0
        # j == 0 (total capacity is 0). So again Profit is 0
        # Initialization already done while creating dp matrix
        
        for i in range(1, n+1):
            for j in range(1, capacity+1):
                # Choice Diagram.
                # Always remember i-1 maps to the val/wt array (i=1, i-1 = 0th index of wt, val array)
                # If w <= W [j] index. Then you have 2 choices.
                # Take -> If you take you make a call on (n) index again (repeated items allowed <only difference from 01 Knapsack>) with reduced weight W - w
                # Do not Take -> You make a call on n-1 index with same weight W
                if wt[i-1] <= j:
                    dp[i][j] = max(val[i-1] + dp[i][j - wt[i-1]], #take so add value but call on n
                                    dp[i-1][j])   # do not take call on n-1
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[n][capacity]
