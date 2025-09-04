class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)  
        dp = [[0 for j in range(m+1)] for i in range(n+1)]

        # Base Condition (Initialization) 
        # if length of any string is 0 then the answer is 0
        # i == 0 or j == 0 -> subproblems where string length is 0 (Hence already initialized)
        for i in range(1, n+1):
            for j in range(1, m+1):
                # Choice Diagram - 
                # If the text at a particular index is equal call both strings on (n-1), (m-1) index and add 1 to the LCS length
                # If they are not equal you have 2 choices
                # Fix string a and call m-1 length on string b or fix string b and call n-1 length on string a and take max of it
                if text1[i-1] == text2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][m]
