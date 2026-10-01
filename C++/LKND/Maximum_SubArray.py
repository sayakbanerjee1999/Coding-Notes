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



# class Solution:
#     def maxSubArray(self, nums: list[int]) -> int:

#         def helper(left, right):
#             if left == right:
#                 return nums[left]

#             mid = (left + right) // 2

#             # Case 1: Maximum subarray in left half
#             left_max = helper(left, mid)

#             # Case 2: Maximum subarray in right half
#             right_max = helper(mid + 1, right)

#             # Case 3: Maximum subarray crossing midpoint

#             # Maximum sum ending at mid
#             curr_sum = 0
#             left_cross = float('-inf')

#             for i in range(mid, left - 1, -1):
#                 curr_sum += nums[i]
#                 left_cross = max(left_cross, curr_sum)

#             # Maximum sum starting at mid + 1
#             curr_sum = 0
#             right_cross = float('-inf')

#             for i in range(mid + 1, right + 1):
#                 curr_sum += nums[i]
#                 right_cross = max(right_cross, curr_sum)

#             cross_max = left_cross + right_cross

#             return max(left_max, right_max, cross_max)

#         return helper(0, len(nums) - 1)
