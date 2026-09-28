import math
import random
from typing import List

class Solution:

    def __init__(self, p: List[float]):
        self.prefix = []
        self.last_positive = -1
        running = 0.0

        for i, ele in enumerate(p):
            if not math.isfinite(ele) or ele < 0:
                raise ValueError(f"invalid probability at index {i}: {ele}")
            if ele > 0:
                self.last_positive = i
            running += ele
            self.prefix.append(running)          # no leading 0

        # LAST POSITIVE IS A FALLBACK FOR CASES THAT OVERFLOW
        # The fallback can't be n − 1, because the trailing items may have probability 0, (EXAMPLE last 2 places - ) [0, 0] 
        # and returning one would silently output an impossible item.
        if self.last_positive == -1:
            raise ValueError("at least one probability must be positive")

        self.total = self.prefix[-1]             # works even if the sum isn't 1

    def pickIndex(self) -> int:
        x = random.random() * self.total         # x in [0, total)
        left, right = 0, len(self.prefix) - 1
        ans = self.last_positive                 # fallback if no prefix > x

        # Find the smallest prefix > x (upper bound, strict)
        while left <= right:
            mid = left + (right - left) // 2
            # THIS IS NOT >= BUT > random.random() [0, total)
            # For p = [0.0, 0.2, 0.5, 0.3, 0.0], random() can return exactly 0.0, and >= would then return index 0, 
            # which has probability 0 (BUG). With >, zero-width intervals are always skipped.
            if self.prefix[mid] > x:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans                               # already an index into p


# Follow-up 2: probabilities that don't sum to 1
# Scaling is already built in. random() * total is equivalent to normalizing, at O(1) per draw 
# instead of O(n) divisions and without adding rounding error to every item. For rejection sampling, 
# either treat the missing mass 1 − S as "no result" and redraw whenever u >= S (acceptance rate S), 
# OR Pick an index uniformly and keep it with probability w[i] / w_max (acceptance rate Σw / (n · w_max)). 

# Each draw is an independent trial with acceptance rate a, so the number of draws is geometric: 
# E = a·1 + (1 − a)(1 + E), which gives E = 1/a. That's 2 when a = 1/2, for example when the 
# # probabilities sum to 0.5. Rejection gets expensive as a → 0, and in that case you should scale instead.
# Case 1: We accept on the first draw <Let acceptance probability a>
# Probability: a. If we accept immediately, we used exactly 1 draw. So this contributes: a⋅1
# Case 2: We reject
# Probability: (1-a). If we reject, we used 1 more draw. So the contribution: E+1 (kind of recursion). (1-a)

# Follow-up 3: very large lists with mass on a few values
# Tiny weights can round away inside a large running sum. accumulate([1e16, 1.0, 1.0, 1.0]) 
# gives [1e16, 1e16, 1e16, 1e16], so items 1–3 become impossible to sample. The usual fix is two-tier sampling. 
# Split the items into the few heavy ones (total mass H) and the long tail (mass T). Flip a coin that picks 
# heavy with probability H / (H + T), then sample within the chosen group from its own prefix array. 
# Most draws hit the tiny heavy array, which is effectively O(1), and the tail keeps its own scale, so 
# its small weights don't round away. Two alternatives: if the weights are fixed and you'll draw many samples, 
# the alias method gives O(1) per draw regardless of skew; if weights change, a Fenwick tree gives O(log n) updates and draws.

# Why does this give the correct probability?
# This is the beautiful part.
# For B:

# Probability of choosing Heavy
# 90 / 100
# Probability of choosing B given Heavy
# 30 / 90

# Therefore:
# P(B)
# = P(Heavy) × P(B | Heavy)
# = 90/100 × 30/90
# = 30/100
# = 30%

# Exactly what we wanted.
