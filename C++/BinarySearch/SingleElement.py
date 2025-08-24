class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        # Base Cases
        if len(nums) == 1:
            return nums[0]
        if nums[0] != nums[1]:
            return nums[0]
        if nums[len(nums)-1] != nums[len(nums)-2]:
            return nums[len(nums)-1]
        
        low = 1
        high = len(nums) - 1

        while low <= high:
            mid = low + (high - low) // 2

            # Condition for a single element
            if nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]:
                return nums[mid]
            
            # On the left half -> Logic 
            # Before the single element duplicate elements (even, odd), (even, odd).
            # After the single element (odd, even), (odd, even) -> because the single element comes in the even place.
            # So to check the left half. If index is even and element at even == element at the next index (odd). On the left half (so search on the right half)
            # Right half will have next element after even as different element
            # If index is odd and element at odd == element at odd - 1 (even). Then also confirms we are at left helf. 
            # If you were in the right half. These properties wouldn't have held
            elif (mid % 2 == 0 and nums[mid] == nums[mid+1]) or (mid % 2 == 1 and nums[mid]==nums[mid-1]):
                low = mid + 1
            else:
                high = mid - 1

        return -1 
