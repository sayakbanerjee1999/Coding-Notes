class Solution:
    def __init__(self, nums: List[int]):
        self.nums = nums
        self.original = self.nums.copy()                # Shallow Copy

    def reset(self) -> List[int]:
        # self.nums = self.original.copy()
        # return self.nums
        return self.original

    def shuffle(self) -> List[int]:
        for i in range(len(self.nums) - 1, -1, -1):
            x = random.randint(0, i)
            self.nums[i], self.nums[x] = self.nums[x], self.nums[i]
        
        return self.nums


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
