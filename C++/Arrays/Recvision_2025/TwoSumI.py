class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        prevMap = {}

        res = []
        for idx, num in enumerate(nums):
            diff = target - num
            # If the other element already exists then return
            if diff in prevMap:
                res.extend([prevMap[diff], idx])
                break
            # Otherwise just update
            prevMap[num] = idx
        
        return res
