class Solution:
    # Solve nth root exactly in the same way but multiple n times

    def helper(self, x: int, mid: int) -> int:
        if mid * mid == x:
            return 1
        elif mid * mid < x:
            return 2
        else:
            return 3 

    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
            
        lo = 1
        hi = x

        ans = -1

        while lo <= hi:
            mid = lo + (hi - lo) // 2

            if self.helper(x, mid) == 1:
                ans = mid
                break
            # If mid element smaller than eleminate left half and search only in right-half (But assign answer as well since smallest integer is needed)
            elif self.helper(x, mid) == 2:
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1
        
        return ans
