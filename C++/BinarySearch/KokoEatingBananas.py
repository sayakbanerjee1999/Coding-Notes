class Solution:
    def timeTaken(self, piles: List[int], speed: int) -> int:
        totalTime = 0
        for n in piles:
            totalTime += ceil(n/speed)
        
        return totalTime

    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # The range shuld be between 1 and max(piles)
        # Keep minimum as 1 because there can be cases with just 1 element and for such cases you would want a bigger search space
        low = 1
        high = max(piles)
        ans = 1e9

        while(low <= high):
            mid = low + (high-low)//2

            # If within limits look for a lower number
            if self.timeTaken(piles, mid) <= h:
                ans = mid
                high = mid - 1
            
            # Look for a higher number
            else:
                low = mid + 1
        
        return ans
