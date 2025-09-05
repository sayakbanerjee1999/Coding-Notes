#User function Template for python3

class Solution:
    #Function to find length of shortest common supersequence of two strings.
    def LCS(self, s1, s2, n, m) -> int:
        dp = [[0 for j in range(m+1)] for i in range(n+1)]
        
        for i in range(1, n+1):
            for j in range(1, m+1):
                if s1[i-1] == s2[j-1]:
                    dp[i][j] = 1+dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][m]
        
        
    def shortestCommonSupersequence(self, s1, s2):
        #code here
        # s1 = "geek", s2 = "eke"
        # Longest Supersequence is s1 + s2 = "geekeke"
        # However, we see that the subsequence ee is there 2 times in the supersequence
        # Se we delete the "ee" once.
        # On careful observation we see that "ee" is nothing but the LCS of s1. s2
        # Hence, the length of the Shortest Common Supersequence = len(s1) + len(s2) - LCS(s1, s2)
        n = len(s1)
        m = len(s2)
        
        lcsLen = self.LCS(s1, s2, n, m)
        
        superseqLen = n+m-lcsLen
        
        return superseqLen
        
