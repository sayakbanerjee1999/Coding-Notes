class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = nums[0] # index 0 (take it)
        prev2 = 0    # index -1 (Do not pick index 0, so rob value = 0 in this case)

        for i in range(1, len(nums)):
            # If you picking current index (Suppose 1) you can only pick nonTake (-1 index). But -1 index is not of bounds so add nonTake to pick only if i > 1 
            pick = nums[i]
            if i > 1:
                pick += prev2
            
            # Do not select current index. So take the prev index (0)
            notPick = 0 + prev

            currMax = max(pick, notPick)
            prev2 = prev
            prev = currMax
        
        return prev
