from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        maxLen = 0
        charsDict = defaultdict(int)

        while(r < len(s)):
            # In the current Window and also in Dict
            if s[r] in charsDict and charsDict[s[r]] >= l:
                l = charsDict[s[r]] + 1
            
            maxLen = max(maxLen, r-l+1)
            charsDict[s[r]] = r
            r += 1
        
        return maxLen

