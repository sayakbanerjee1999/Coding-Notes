class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        n = len(prices)
        dp = [[[0 for _ in range(k+1)] for _ in range(2)] for _ in range(n+1)]

        for i in range(n-1, -1, -1):
            for can_buy in [0, 1]:
                for transactions_left in range(1, k+1):
                    if can_buy:
                        dp[i][1][transactions_left] = max(
                            -prices[i] + dp[i+1][0][transactions_left],  # buy
                            dp[i+1][1][transactions_left]                # skip
                        )
                    else:
                        dp[i][0][transactions_left] = max(
                            prices[i] + dp[i+1][1][transactions_left - 1],  # sell
                            dp[i+1][0][transactions_left]                   # skip
                        )

        return dp[0][1][k]  # start from day 0, can_buy=True, 2 transactions
