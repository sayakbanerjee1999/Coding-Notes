class Solution:
    def findMin(self, nums: List[int]) -> int:
        hi = len(nums) - 1
        lo = 0

        ans = 1e9

        while lo <= hi:
            mid = lo + (hi-lo)//2

            # If lo <= hi then the search space is already sorted. lo is the answer
            if nums[lo] <= nums[hi]:
                ans = min(ans, nums[lo])
                break
            
            # Left Sorted search right
            if nums[mid] >= nums[lo]:
                lo = mid + 1
            else:
                hi = mid                # mid - 1 will leave out an element which you do not want 
        
        return ans
