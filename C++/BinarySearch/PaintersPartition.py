class Solution:
    # Same Question as Pages Partition
    def getPainters(self, arr, mid):
        numPainters = 1
        numPainted = 0
        
        for p in arr:
            if p + numPainted <= mid:
                numPainted += p
            else:
                numPainters += 1
                numPainted = p
        
        return numPainters
        
    
    def minTime (self, arr, k):
        # code here
        if len(arr) < k:
            return -1
            
        low = max(arr)
        high = sum(ele for ele in arr)
        
        ans = -1
        
        while low <= high:
            mid = low + (high - low) // 2
            
            numPainters = self.getPainters(arr, mid)
            
            if numPainters <= k:
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        
        return ans
        
