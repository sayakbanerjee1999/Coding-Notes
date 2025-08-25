class Solution:
    def lowerBound(self, arr, target):
        # code here
        # Be definition smallest arr[x] >= target
        lo = 0
        hi = len(arr) - 1
        
        ans = -1
        
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            
            # If the element at mid is >= target it can be a lower bound. 
            # But we must check for smaller elements as well so check left half again
            if arr[mid] >= target:
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1
        
        return len(arr) if ans == -1 else ans
