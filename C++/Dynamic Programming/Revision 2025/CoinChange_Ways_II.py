class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # Exactly subset sum problem but with unbounded knapsack condition
        n = len(coins)
        dp = [[0 for j in range(amount+1)] for i in range(n+1)]

        # Base Case (Initialization)
        # If i == 0; no coins no way to build up the sum -> 0
        # If j == 0; (subproblem with target sum = 0) always 1 way of with {} subset
        for i in range(n+1):
            dp[i][0] = 1
        
        # Unbounded knapsack since repetations allowed
        for i in range(1, n+1):
            for j in range(1, amount+1):
                # Choice
                # if coins.value <= j(target)
                # Take -> call on n index with reduced target (amount - j). Since repeatitions allowed
                # Do not take -> call on n-1 index with same target
                if coins[i-1] <= j:
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]     # take + no take
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[n][amount]
