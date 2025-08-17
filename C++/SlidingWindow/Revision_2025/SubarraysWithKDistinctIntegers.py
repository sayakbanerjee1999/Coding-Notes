from collections import defaultdict
class Solution:
    def helperFunc(self, nums: List[int], goal: int) -> int:
        if goal < 0:
            return 0
            
        maxLen, l, r = 0, 0, 0
        integerDict = defaultdict(int)
        countWindows = 0

        while r < len(nums):
            integerDict[nums[r]] += 1

            while len(integerDict) > goal:
                integerDict[nums[l]] -= 1
                if integerDict[nums[l]] == 0:
                    del integerDict[nums[l]]
                l += 1
            
            if len(integerDict) <= goal:
                countWindows += (r-l+1)
            
            r += 1
        
        return countWindows


    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        # Subarrays with <= K Distinct Integers - Subarrays with <=K-1 Distinct Integers
        subarraysWithK = self.helperFunc(nums, k)
        subarraysWithK_1 = self.helperFunc(nums, k-1)

        return (subarraysWithK - subarraysWithK_1)
