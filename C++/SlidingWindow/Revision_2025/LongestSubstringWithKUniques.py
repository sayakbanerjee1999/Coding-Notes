from collections import defaultdict

class Solution:
    def longestKSubstr(self, s, k):
        # code here
        l, r, maxLen = 0, 0, 0
        charsDict = defaultdict(int)
        
        while r < len(s):
            charsDict[s[r]] += 1
            
            if len(charsDict) > k:
                charsDict[s[l]] -= 1
                if charsDict[s[l]] == 0:
                    del charsDict[s[l]]
                l += 1
            
            if len(charsDict) == k:
                maxLen = max(maxLen, r-l+1)
            
            r += 1
        
        return maxLen if maxLen > 0 else -1
