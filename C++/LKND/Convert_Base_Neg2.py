# Every step must satisfy n = q · base + r, with r being 0 or 1, so q = (n − r) / base.

# Base 2: Python's n % 2 is already 0 or 1, and n // 2 is the quotient that goes with it, so n // 2 works on its own.

# Base -2: Python's n % -2 is 0 or -1, so n // -2 is the quotient that goes with a remainder of -1. 
# That is wrong for us when n is odd. The fix is to choose r = n % 2 (0 or 1) and compute q = (n − r) // -2, which divides exactly.

# For example, with n = 3, (3 − 1) // -2 = -1 ✓, but 3 // -2 = -2 ✗.

class Solution:
    def baseNeg2(self, n: int) -> str:
        if n == 0:
            return "0"
        digits = []
        while n != 0:
            r = n % 2              # in Python this is always 0 or 1, even for negative n
            digits.append(str(r))
            # n = n // 2 (If positive)
            n = (n - r) // -2      # n - r is even, so this division is exact
        return "".join(reversed(digits))

# Generic Code that works for every case
# class Solution:
#     def convertBase(self, n: int, base: int) -> str:
#         if n == 0:
#             return "0"
#         digits = []
#         while n != 0:
#             if base > 0:
#                 # Use this when positive base (requires n >= 0, otherwise the loop never ends)
#                 r = n % base              # digit in 0 .. base-1
#                 n = n // base             # for a positive base, % and // already give a valid digit
#             else:
#                 # Use this when negative base
#                 r = n % abs(base)         # digit in 0 .. |base|-1, never negative
#                 n = (n - r) // base       # exact division, since n - r is a multiple of base
#             digits.append(str(r))         # digits come out lowest first (str(r) works for |base| <= 10)
#         return "".join(reversed(digits))  # reverse so the highest digit is first
