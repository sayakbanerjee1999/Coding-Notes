class Solution:
    def LCS(self, s: str, reverse_s: str, n: int) -> int:
        dp = [[0 for i in range(n+1)] for j in range(n+1)]

        # Normal LCS initialization i==0 || j==0 = 0
        for i in range(1, n+1):
            for j in range(1, n+1):
                if s[i-1] == reverse_s[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][n]

    def minInsertions(self, s: str) -> int:
        # Let's take the example of "mbadm"
        # Longest Palindromic Subsequence of "mbadm" is "mam" (len 3)
        # So you can make 2 deletions to convert mbadm to mam.
        # Reversely, you can make 2 insertions to convert "mam" to "mbadm", bd -> You can put it anywhere doesn't matter. But 2 insertions are required
        # So insertions = deletions = len(s) - LCS.
        # LCS length always varies from 0 -> min(s1, s2).
        # min(s1, s2) if s1/s2 is the entire substring

        n = len(s)
        reverse_s = s[::-1]

        lcsLEN = self.LCS(s, reverse_s, n)

        return n - lcsLEN
