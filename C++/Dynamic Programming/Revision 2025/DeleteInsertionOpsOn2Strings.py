class Solution:
    def LCS(self, word1: str, word2: str, n: int, m: int) -> int:
        dp = [[0 for j in range(m+1)] for i in range(n+1)]

        for i in range(1, n+1):
            for j in range(1, m+1):
                if word1[i-1] == word2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[n][m]

    def minDistance(self, word1: str, word2: str) -> int:
        # This question is very similar to delete and insert operations to make string a = string b
        # The case here -> "leetcode" and "etco"
        # LCS between the two strings "etco". Hence we delete the other 4 character

        # Let's take the example of heap and pea
        # LCS -> ea
        # heap -> ea (2 deletions)
        # pea -> ea (1 deletions)
        # In insertions we would have added "p" to LCS "ea" to get pea
        # Total deletions = 3
        # (len(s1) - LCS) + (len(s2) - LCS)
        # 1st term (deletions) -> 2nd term (insertion / deletion) -> according to question

        n = len(word1)
        m = len(word2)

        LCSLEN = self.LCS(word1, word2, n, m)

        deletions_w1 = n - LCSLEN
        deletions_w2 = m - LCSLEN

        return deletions_w1 + deletions_w2
