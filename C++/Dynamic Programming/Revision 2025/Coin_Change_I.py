# Minimum number of coins to get Target

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [[1e8 for j in range(amount+1)] for i in range(n+1)]

        # Base Case (Initialization)
        # If i == 0; no coins no way to build up the sum -> 1e8 since we need to return minimum
        # If j == 0; (target sum = 0) Take 0 coins to get target = 0. Minimum number of coins = 0.
        for i in range(n+1):
            dp[i][0] = 0
        
        for i in range(1, n+1):
            for j in range(1, amount+1):
                # Choice
                # if coins.value <= j(target)
                # Take -> call on n index with reduced target (amount - j). Since repeatitions allowed. (Increase the count by 1 -> Change from Coin Change II)
                # Do not take -> call on n-1 index with same target
                # However, here we are not counting ways but the minimum so replace + with min
                if coins[i-1] <= j:
                    dp[i][j] = min(1 + dp[i][j-coins[i-1]],      # Take -> count increases by 1 and remove from target sum(j)
                                    dp[i-1][j])              # Do not take
                else:
                    dp[i][j] = dp[i-1][j]
        
        return dp[n][amount] if dp[n][amount] != 1e8 else -1
