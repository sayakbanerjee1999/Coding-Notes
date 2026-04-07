class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        if sum(nums)%k != 0:
            return False

        used = [False] * len(nums)
        target = sum(nums) / k

        if max(nums) > target:
            return False

        def backtrack(i, k, subsetSum):
            """
            i -> keeps track of the index
            k -> keeps track of the number of subsets remaining
            subsetSum -> curr subset sum
            """
            # All subsets formed
            if k == 0:
                return True
            # If target accomplished -> start from beginning of the array; with k-1; 
            # Used array will take care of which elements can be used
            if subsetSum == target:
                return backtrack(0, k-1, 0)

            for j in range(i, len(nums)):
                # Skip if either j is used or +nums[j] > target
                if used[j] or subsetSum + nums[j] > target or (j > 0 and nums[j] == nums[j-1] and not used[j-1]):
                    continue
                
                # Otherwise mark used[j] as True
                used[j] = True
                # Call the backtrack on the remaining portion of the array
                if backtrack(j+1, k, subsetSum+nums[j]):
                    return True

                # Backtrack
                used[j] = False
            
            return False
        
        return backtrack(0, k, 0)
