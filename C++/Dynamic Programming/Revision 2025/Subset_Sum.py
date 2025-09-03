class Solution:
    def isSubsetSum (self, arr, sum):
        # code here 
        n = len(arr)
        dp = [[False for j in range(sum+1)] for i in range(n+1)]
        
        # Initialize (base cases)
        # i == 0; (Subproblem with no array) No array. No way to get target so False
        # j == 0; target is 0. Always possible by taking a {} subset
        for i in range(n+1):
            for j in range(sum+1):
                if i==0:
                    dp[i][j] = False
                if j == 0:
                    dp[i][j] = True
        
        
        for i in range(1, n+1):
            for j in range(1, sum+1):
                # Same Choice as 0/1 Knapsack
                # If arr[i-1] <= target (j index); you can take or not take
                # If you take take call on n-1 with reduced target sum else just call on target sum.
                # Here you want to return boolean -> so instead of max just take ||
                if arr[i-1] <= j:
                    dp[i][j] = dp[i-1][j - arr[i-1]] or dp[i-1][j]
                
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[n][sum]
                    
        
        
        
