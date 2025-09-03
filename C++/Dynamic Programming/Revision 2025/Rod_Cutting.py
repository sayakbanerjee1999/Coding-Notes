#User function Template for python3
import numpy as np
class Solution:
    def cutRod(self, price):
        #code here
        # 2d solution might not be required
        # rod_length = len(price)
        # rod_array = list(np.arange(1,rod_length+1, dtype = int))
        # # print(rod_array)
        
        # dp = [[0 for j in range(rod_length+1)] for i in range(rod_length+1)]
        
        # # Initialization (Base Condition)
        # # Column Rod Length, Rows maps to price
        # # if i == 0; (no element in array) -> Price = 0
        # # if j == 0; (rod_length = 0 in this subproblem) -> Price = 0
        
        # for i in range(1, rod_length+1):
        #     for j in range(1, rod_length+1):
        #         if rod_array[i-1] <= j:
        #             dp[i][j] = max(price[i-1] + dp[i][j-rod_array[i-1]], # Take and pass with reduced length of rod with n index because multiple allowed
        #                             dp[i-1][j])         # Do not take so call on n-1
        #         else:
        #             dp[i][j] = dp[i-1][j]
        
        # return dp[rod_length][rod_length]
        
        # 1d
        rod_length = len(price)
        dp = [0] * (rod_length+1)
        
        for i in range(1, rod_length+1):
            for j in range(i, rod_length+1):
                dp[j] = max(dp[j], price[i-1] + dp[j-i]);
        
        return dp[rod_length]
        
