class Solution:
    def perfectSum(self, arr, K):
        # code here 
        n = len(arr)
        dp = [[0 for j in range(K+1)] for i in range(n+1)]
        MOD = 10**9 + 7
        
        # Initialize (base cases)
        # i == 0; (Subproblem with no array) No array. No way to get target so 0
        # j == 0; target is 0. Always possible by taking a {} subset. 1
        for i in range(n+1):
            for j in range(sum+1):
                if i==0:
                    dp[i][j] = 0
                if j == 0:
                    dp[i][j] = 1
        
        
        for i in range(1, n+1):
            for j in range(1, sum+1):
                # Same Choice as 0/1 Knapsack
                # If arr[i-1] <= target (j index); you can take or not take
                # If you take take call on n-1 with reduced target sum else just call on target sum.
                # Here you want to return count -> so instead of || just take +
                if arr[i-1] <= j:
                    dp[i][j] = (dp[i-1][j - arr[i-1]] + dp[i-1][j])%MOD
                
                else:
                    dp[i][j] = (dp[i-1][j])%MOD
        
        return (dp[n][sum] % MOD)
