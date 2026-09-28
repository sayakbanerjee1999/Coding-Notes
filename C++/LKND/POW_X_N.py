# O(log(n))

class Solution:
    def myPow(self, x: float, n: int) -> float:
        # Divide and Conquer
        def helper(x, n):
            # Base Case
            if x == 0: return 0
            if n == 0: return 1

            # Recurse
            res = helper(x, n//2)
            res = res * res
            # What happens when n is odd.
            # You multiply x; 2^5 = 2^1 * 2^2 * 2^2
            return x * res if n%2 else res
        
        res = helper(x, abs(n))
        return res if n >= 0 else 1 / res
