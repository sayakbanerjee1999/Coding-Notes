#User function Template for python3

class Solution:
	def LongestRepeatingSubsequence(self, s):
		# Code here
        # You find the LCS between (s, s)
        # Naively -> LCS of s and s will be s but while calculating LCS 
        # However, you only want to calculate LCS for elements not at the same index
        # i!=j in that way you get make sure you are taking unique characters only
        # but you don't want to consider 		
        
        n = len(s)
        dp = [[0 for j in range(n+1)] for i in range(n+1)]
        
        # Same initialization as LCS
        for i in range(1, n+1):
            for j in range(1, n+1):
                if s[i-1] == s[j-1] and i != j:         # Only addition i!=j
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][n]
