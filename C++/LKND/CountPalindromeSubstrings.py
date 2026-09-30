class Solution:
    def countPalindrome(self, i: int, j: int, s: str) -> int:
        cnt = 0
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
            cnt += 1
        return cnt

    def countSubstrings(self, s: str) -> int:
        # 2 ways to check.
        # Odd Length: Start from a single char; go left and right; if char[left] == char[right] that is also a palindrome. Add it to res
        # Even Length: Start from (i, i+1); go left and right; if char[i]==char[i+1] and char[left] == char[right] that is also a palindrome. Add it to res
        res = 0

        for i in range(len(s)):
            res += self.countPalindrome(i, i, s)
            res += self.countPalindrome(i, i+1, s)

        return res
