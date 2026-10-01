# O(n + n/2 + n/4 + n/8) == O(2n) = O(n) <- Avg
# Worst Case - O(n^2) 

# Worked example

# nums = [6, 1, 8, 2, 3, 9, 4], k = 3 (3rd largest). Sorted, this is [1, 2, 3, 4, 6, 8, 9], so the answer should be 6.
# First, k = 7 - 3 = 4. The 3rd largest element is the one at index 4 of the sorted array.

# First call, quickSelect(0, 6): pivot = nums[6] = 4, p = 0
# i	nums[i]	≤ 4?	action	            array after	            p
# 0	    6	no	    skip	            [6, 1, 8, 2, 3, 9, 4]	0
# 1	    1	yes	    swap idx 0 ↔ 1	    [1, 6, 8, 2, 3, 9, 4]	1
# 2	    8	no	    skip	            [1, 6, 8, 2, 3, 9, 4]	1
# 3	    2	yes	    swap idx 1 ↔ 3	    [1, 2, 8, 6, 3, 9, 4]	2
# 4	    3	yes	    swap idx 2 ↔ 4	    [1, 2, 3, 6, 8, 9, 4]	3
# 5	    9	no	    skip	            [1, 2, 3, 6, 8, 9, 4]	3

# Final swap: when the loop finishes, the array is [1, 2, 3 | 6, 8, 9 | 4]. p = 3 
# points at the first big element (6). Swapping nums[3] with the pivot at nums[6] gives:

# [1, 2, 3, 4, 8, 9, 6]
#           ↑
#           p = 3

# Everything left of index 3 is ≤ 4 and everything right of it is > 4, so 4 is now at the 
# index it would have in the fully sorted array. Index 3 holds 4 in [1, 2, 3, 4, 6, 8, 9] too.

class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        k = len(nums) - k
        # If k smallest -> just replace k = k - 1

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
