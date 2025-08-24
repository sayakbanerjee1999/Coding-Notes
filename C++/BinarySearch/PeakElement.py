class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        # Edge Cases if Peak Element at the boundary
        if nums[0] > nums[1]:
            return 0
        if nums[len(nums)-1] > nums[len(nums)-2]:
            return len(nums)-1

        # Shrinked since already checked in edge cases
        low = 1
        hi = len(nums)-2

        while low <= hi:
            mid = low + (hi-low) // 2

            # If current element greater than both left and right its a peak element
            # Condition for Peak
            if nums[mid-1] < nums[mid] and nums[mid] > nums[mid+1]:
                return mid
            
            # If nums[mid] > nums[mid - 1]. Its on the increasing slope (imagine the mountain), so the peak must be on the right (eliminate the right half). low = mid + 1
            elif nums[mid] > nums[mid - 1]:
                low = mid + 1
            else:                       # Takes care if we are stuck at a local minima
                hi = mid - 1
        
        return -1

        
