import random

class Solution:

    def __init__(self, w: List[int]):
        self.w = w
        self.prefix = [0]

        for ele in self.w:
            self.prefix.append(self.prefix[-1] + ele)

    def pickIndex(self) -> int:
        x = random.randint(1, self.prefix[-1])
        left, right = 1, len(self.prefix) - 1

        ans = -1

        # Find the smallest prefix >= x (Lower Bound)
        while left <= right:
            mid = left + (right - left) // 2

            if self.prefix[mid] >= x:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
    
        # IReturn the original array index (subtract 1 due to 0-padding in prefix array)
        return (ans - 1)




# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()
