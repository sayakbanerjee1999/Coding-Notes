class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = 1
        res = [1]*len(nums)
        
        # Put prefix products at each cell
        for i in range(len(nums)):
            res[i] = prefix
            prefix = prefix * nums[i]
        
        # Multiply by suffix
        suffix = 1
        for i in range(len(nums)-1, -1, -1):
            res[i] = res[i] * suffix
            suffix = suffix * nums[i]

        return res
