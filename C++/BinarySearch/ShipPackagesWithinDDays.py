class Solution:
    def shippingDays(self, weights: List[int], capacity: int) -> int:
        # Start Count Days from 1 otherwise you will not count Day 1
        countDays = 1
        currentWeight = capacity
        for wt in weights:
            if wt <= currentWeight:
                currentWeight -= wt
            else:
                countDays += 1
                currentWeight = capacity
                currentWeight -= wt
        return countDays    

    def shipWithinDays(self, weights: List[int], days: int) -> int:
        # Range [max(weights), sum(weights)]
        # Minimum is max(weights) because you want to carry that in 1 day
        # Max is sum(weights) because you may want to ship everything in a day
        low = max(weights)
        high = sum(wt for wt in weights)
        ans = 1e9

        while low <= high:
            mid = low + (high - low)//2

            if self.shippingDays(weights, mid) <= days:
                ans = mid
                high = mid - 1
            
            else:
                low = mid + 1
        
        return ans
