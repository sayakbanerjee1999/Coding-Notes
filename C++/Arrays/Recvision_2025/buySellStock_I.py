class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy_price = prices[0]
        profit = 0

        for price in prices[1:]:
            buy_price = min(buy_price, price)
            # print(buy_price)
            profit = max(profit, price - buy_price)
        
        return profit
