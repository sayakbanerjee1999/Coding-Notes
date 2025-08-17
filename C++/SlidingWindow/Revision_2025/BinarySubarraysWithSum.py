class Solution:
    # Helper function to find the number of subarrays with sum <= goal
    def helperFunc(self, nums: List[int], goal: int) -> int:
        if goal < 0:
            return 0

        l, r, countWindows = 0, 0, 0
        sum_ = 0

        while r < len(nums):
            sum_ += nums[r]

            while sum_ > goal:
                sum_ -= nums[l]
                l += 1
            
            if sum_ <= goal:
                # Number of subwindows between l, r = r - l + 1
                countWindows += r-l+1
            
            r += 1
        
        return countWindows


    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        windows_le_goal = self.helperFunc(nums, goal)
        windoes_le_goal_1 = self.helperFunc(nums, goal - 1)

        return windows_le_goal-windoes_le_goal_1
        
