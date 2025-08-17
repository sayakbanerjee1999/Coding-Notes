class Solution:
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


    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        # Convert the Problem to Subarrays with Binary Sum. Replace Odd numbers with 1 and even numbers with 0. 
        # Essentially you are now finding the number of subarrays with sum = k
        copyNums = []
        for i in range(len(nums)):
            copyNums.append(nums[i]%2)
        
        windows_le_goal = self.helperFunc(copyNums, k)
        windoes_le_goal_1 = self.helperFunc(copyNums, k - 1)

        return windows_le_goal-windoes_le_goal_1
