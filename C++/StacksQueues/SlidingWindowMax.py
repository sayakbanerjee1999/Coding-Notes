from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        # Instead of storing values in the deque we will be storing the indices
        l, r = 0, 0
        res = []
        dq = deque()

        while r < len(nums):
            # If dq is not empty and the element at the right end is less than the element to be inserted. Continue removing
            while dq and nums[dq[-1]] <= nums[r]:
                dq.pop()
            
            dq.append(r)

            # If out of window remove 
            # Current Left index > the index stored on the left end
            if l > dq[0]:
                dq.popleft()
            
            if r-l+1 == k:
                # The left from the left end will always be the maximum
                res.append(nums[dq[0]])
                l += 1
            
            r += 1

        return res
