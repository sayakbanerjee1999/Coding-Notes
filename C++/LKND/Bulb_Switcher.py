# Key insight: A bulb at position k gets toggled in round d if and only if d is a divisor of k. 
# For example, bulb 6 gets toggled in rounds 1, 2, 3, and 6 (since these are all divisors of 6).

# Since each bulb starts off, it will be on after all rounds if it's toggled an odd number of 
# times, which happens when the bulb's position has an odd number of divisors. 
# Only perfect square numbers have an odd number of divisors (because for perfect squares, one divisor pairs with itself).

# Therefore, the problem reduces to counting how many perfect squares exist from 1 to n, which equals ⌊√n⌋.

import math

class Solution:
    def bulbSwitch(self, n: int) -> int:
        # The number of perfect squares from 1 to n is floor(sqrt(n))
        return int(math.sqrt(n))

# The most critical pitfall in this solution is relying on floating-point arithmetic for the square root calculation. 
# Due to floating-point representation limitations, math.sqrt(n) might produce results like 4.999999999999 instead 
# of exactly 5.0 for perfect squares, leading to incorrect results when converting to integer.

# Solution: Use integer-only arithmetic to avoid floating-point errors entirely:
class Solution:
    def bulbSwitch(self, n: int) -> int:
        # Integer-only solution using binary search
        if n == 0:
            return 0
      
        left, right = 1, n
        result = 1
      
        while left <= right:
            mid = (left + right) // 2
            if mid * mid <= n:
                result = mid
                left = mid + 1
            else:
                right = mid - 1
      
        return result
