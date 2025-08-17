class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        l, r, countZeros = 0, 0, 0
        maxLen = 0
        while r < len(nums):
            if nums[r] == 0:
                countZeros += 1
            
            # the while here can be replaced by if -> as we make sure we move the window by the same length 
            # (we have already got an answer and want to get windows > the current one. Striver playlist)
            if countZeros > k:
                if nums[l] == 0:
                    countZeros -= 1
                l = l+1

            if countZeros <= k:
                maxLen = max(maxLen, r-l+1)
            
            r += 1
        
        return maxLen
