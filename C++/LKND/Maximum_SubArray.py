# Kadane's Algorithm

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if all(x<0 for x in nums):
            return max(nums)
        
        max_so_far, max_ending_here = 0, 0

        for num in nums:
            max_ending_here += num

            max_so_far = max(max_so_far, max_ending_here)

            if max_ending_here < 0:
                max_ending_here = 0
        
        return max_so_far
