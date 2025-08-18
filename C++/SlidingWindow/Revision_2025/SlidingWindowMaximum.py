from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        l, r = 0, 0
        res = []
        dq = deque()

        # Store index and not values
        while r < len(nums):
            # Pop smaller Values from the DQ before pushing bigger elements
            while dq and nums[dq[-1]] < nums[r]:
                dq.pop()
            
            dq.append(r)

            # Remove elements from DQ 
            if l > dq[0]:
                dq.popleft()
            
            # If window size is == k. Take result and then shrink
            if r - l + 1 == k:
                # Append from the back. Highest element is at the back of the array. 
                # You keep smaller elements to right but delete smaller elements to the left.
                res.append(nums[dq[0]])  
                l += 1
        
            r += 1
        
        return res
