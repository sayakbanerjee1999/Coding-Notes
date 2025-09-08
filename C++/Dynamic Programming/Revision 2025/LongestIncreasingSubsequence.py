class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # LCS between nums and sorted(nums)
        # Sorted Nums is already in sorted order. So the subsequence which matches the increasing order is the LIS
        n = len(nums)
        sorted_nums = sorted(set(nums))         # Remove duplicates as strictly increasing needed
        m = len(sorted_nums)

        dp = [[0 for j in range(m+1)] for i in range(n+1)]

        for i in range(1, n+1):
            for j in range(1, m+1):
                if nums[i-1] == sorted_nums[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][m]

        # Using 1-D
        # dp = [1 for i in range(n+1)]
        # max_len = 1

        # for i in range(n): 
        #     for j in range(i): 
        #         if nums[i] > nums[j]: 
        #             dp[i] = max(dp[i], dp[j] + 1) 
        #         max_len = max(max_len, dp[i]) 
        
        # return max_len
