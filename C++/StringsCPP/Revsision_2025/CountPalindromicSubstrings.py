class Solution:
    def countPalindrome(self, s: str, l: int, r: int) -> int:
        res = 0
        while l >= 0 and r < len(s) and s[l] == s[r]:
            res += 1
            l -= 1
            r += 1
        
        return res

    def countSubstrings(self, s: str) -> int:
        # Two Cases - 
        # Odd length (Consider only one element. It is a palindrom. Move leftward and rightward. If both these elements are equal it is again a palindrome)
        # Even Lengtn (Consider element at i and i+1). When they are equal it is a palindrome. Now move leftward and rightward. If both these elements are equal it is a palindrome again
        res = 0 
        for idx, ch in enumerate(s):
            res += self.countPalindrome(s, idx, idx)
            res += self.countPalindrome(s, idx, idx+1)
        
        return res
