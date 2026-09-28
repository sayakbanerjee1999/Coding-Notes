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
            if self.prefix[mid] > x:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans                               # already an index into p
