class Solution:
    def maxTastiness(self, price: List[int], tastiness: List[int], maxAmount: int,maxCoupons: int) -> int:
        memo = {}

        def dfs(fruit_index, remaining_amount, remaining_coupons):
            # Base case
            if fruit_index == len(price):
                return 0

            # Check if state was already calculated
            state = (fruit_index, remaining_amount, remaining_coupons)

            if state in memo:
                return memo[state]

            # Option 1: Skip current fruit
            max_tastiness = dfs(
                fruit_index + 1, remaining_amount, remaining_coupons
            )

            # Option 2: Buy at full price
            if remaining_amount >= price[fruit_index]:
                max_tastiness = max(
                    max_tastiness, dfs(fruit_index + 1, remaining_amount - price[fruit_index], remaining_coupons)
                    + tastiness[fruit_index]
                )

            # Option 3: Buy with coupon
            half_price = price[fruit_index] // 2
            if remaining_amount >= half_price and remaining_coupons > 0:
                max_tastiness = max(max_tastiness, dfs(
                        fruit_index + 1, remaining_amount - half_price, remaining_coupons - 1
                    ) + tastiness[fruit_index]
                )

            # Store answer for this state
            memo[state] = max_tastiness

            return max_tastiness

        return dfs(0, maxAmount, maxCoupons)
