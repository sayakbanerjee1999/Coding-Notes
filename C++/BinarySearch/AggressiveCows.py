class Solution:
    def numberOfCows(self, stalls, dist) -> int:
        count = 1       # Place Cow 1 at index 0
        
        for i in range(1, len(stalls)):
            if stalls[i] - stalls[i-1] >= dist:
                count += 1
            else:
                continue
        
        return count
        
    def aggressiveCows(self, stalls, k):
        high = max(stalls) - min(stalls)
        low = 1
        
        ans = -1
        
        while(low <= high):
            mid = low + (high - low)//2
            
            if self.numberOfCows(stalls, mid) >= k:
                ans = mid
                low = mid + 1       # We need to maximize the answer so search bigger
            
            else:
                high = mid - 1
        
        return ans
        
        
