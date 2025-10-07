class Solution:
    def canJump(self, nums: List[int]) -> bool:
        maxIndex = 0
        for i in range(len(nums)):
            if maxIndex < i:
                return False
            maxIndex = max(i+nums[i], maxIndex)
            if maxIndex >= len(nums)-1:
                return True
        
        return True
        
