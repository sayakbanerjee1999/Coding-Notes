class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        jumps = 0
        maxIndex = 0
        end = 0  # end of current jump

        for i in range(n-1):  # we don't need to jump from the last index
            maxIndex = max(maxIndex, i + nums[i])

            # if we reach the end of current jump, increase jump count
            if i == end:
                jumps += 1
                end = maxIndex

        return jumps
