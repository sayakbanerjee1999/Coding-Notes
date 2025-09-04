class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        # LCS range -> (0, min(s1, s2)). the smaller substring can a complete subsequence. This is what is being asked
        # If len(LCS) == len(s) then is subsequence; else false
        # If we didn't know which one of the strings were smaller
        # We could have checked lcsLEN == min(s1, s2) <True> else <False>
        if len(s) > len(t):
            return False
        
        n = len(s)
        m = len(t)
        dp = [[0 for j in range(m+1)] for i in range(n+1)]

        for i in range(1, n+1):
            for j in range(1, m+1):
                if s[i-1] == t[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return True if dp[n][m] == len(s) else False
