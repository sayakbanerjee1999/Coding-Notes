class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        # Longest Palindromic Subsequence is just finding the lCS between string s and reverse(s)
        # "bbbab", "babbb" -> So, LCS between them is "bbbb"
        # "axccdab", "badccxa" -> LCS is "acca"
        reverse_s = s[::-1]
        n = len(s)
        dp = [[0 for j in range(n+1)] for i in range(n+1)]

        # Same Initialization -> 0 where substrings is 0 (subproblems)

        for i in range(1, n+1):
            for j in range(1, n+1):
                if s[i-1] == reverse_s[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][n]
