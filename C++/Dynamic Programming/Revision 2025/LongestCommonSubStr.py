#User function Template for python3

class Solution:
    def longestCommonSubstr(self, s1, s2):
        # code here
        n = len(s1)
        m = len(s2)
        
        dp = [[0 for j in range(m+1)] for i in range(n+1)]
        
        # Base Condition (Initialization) 
        # if length of any string is 0 then the answer is 0
        # i == 0 or j == 0 -> subproblems where string length is 0 (Hence already initialized)
        
        # To get the maximum value in dp matrix
        maxi = 0
        for i in range(1, n+1):
            for j in range(1, m+1):
                # Choice Diagram - 
                # If the text at a particular index is equal call both strings on (n-1), (m-1) index and add 1 to the LCS length
                # If they are not equal you have only 1 choice
                # Start from 0 again (Substring is continuous) -> So as soon as not match break and start again 
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                    maxi = max(maxi, dp[i][j])
                else:
                    dp[i][j] = 0
        
        return maxi
