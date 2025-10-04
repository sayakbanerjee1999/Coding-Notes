class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # If all positive then maxProduct = product of all elements
        # If even negatives then maxProduct = product of all elements
        # If odd negative (max(prefix, suffix products))
        # If zeros (set product as 1 again)
        prefix, suffix = 1, 1
        maxProd = float('-inf')

        for idx, num in enumerate(nums):
            prefix = prefix * num
            suffix = suffix * nums[len(nums)-idx-1]

            maxProd = max(maxProd, max(prefix, suffix))

            if prefix == 0:
                prefix = 1
            if suffix == 0:
                suffix = 1
        
        return maxProd
