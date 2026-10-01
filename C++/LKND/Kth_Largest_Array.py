# O(n + n/2 + n/4 + n/8) == O(2n) = O(n) <- Avg
# Worst Case - O(n^2) 

class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        k = len(nums) - k

        def quickSelect(l, r):
            pivot, p = nums[r], l

            for i in range(l, r):
                if nums[i] <= pivot:
                    nums[p], nums[i] = nums[i], nums[p]
                    p += 1
            
            nums[p], nums[r] = nums[r], nums[p]

            if p > k:
                # Find in left half
                return quickSelect(l, p-1)
            elif p < k:
                # Find in right half
                return quickSelect(p+1, r)
            else:
                return nums[p]

        return quickSelect(0, len(nums)-1)
