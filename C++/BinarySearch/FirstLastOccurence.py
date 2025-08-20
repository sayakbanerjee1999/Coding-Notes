class Solution:
    def firstOccurence(self, nums:List[int], target: int, lo: int, high: int) -> int:
        # Modify a bit for this question as we need exact match)
        ans = -1
        while(lo <= high):
            mid = lo + (high - lo) // 2

            # There still might be your answer on the left side (First Occurence)
            if nums[mid] == target:
                high = mid - 1
                ans = mid
            elif nums[mid] < target:
                lo = mid + 1
            else:                   # Greater
                high = mid - 1
        
        return ans
    
    def lastOccurence(self, nums:List[int], target: int, lo: int, high: int) -> int:
        # Definition -> arr[x] >= target
        ans = -1
        while(lo <= high):
            mid = lo + (high - lo) // 2

            # There still might be your answer on the Right side (Last Occurence)
            if nums[mid] == target:
                lo = mid + 1
                ans = mid
            elif nums[mid] < target:
                lo = mid + 1
            else:                   # Greater
                high = mid - 1
        
        return ans
        
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if len(nums) == 0:
            return [-1, -1]

        low = 0
        high = len(nums)-1

        first = self.firstOccurence(nums, target, low, high)
        last = self.lastOccurence(nums, target, low, high)

        if nums[first] == target and nums[last] == target:
            return [first, last]
        else:
            return [-1, -1]
