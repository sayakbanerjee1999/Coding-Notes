class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Step 1 - we want the longest prefix. Find out the break point where arr[i] < arr[i+1]. Monotonically increasing breaks
        index = -1
        for idx in range(len(nums) - 2, -1, -1):
            if nums[idx] < nums[idx+1]:
                index = idx
                break
        
        # If index = -1 then the array is already the highest value. So next permutation will be the reverse(lowest value the list can take)
        if index == -1:
            nums.reverse()
            return
        
        # Next swap the element which is just greater than the break point element
        for idx in range(len(nums)-1, index, -1):
            if nums[idx] > nums[index]:
                nums[index], nums[idx] = nums[idx], nums[index]
                break
        
        # Sort the remaining elements in ascending order
        nums[index+1:] = reversed(nums[index+1:])

        return nums
        
