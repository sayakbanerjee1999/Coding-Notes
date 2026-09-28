from collections import defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l, r = 0, 0
        minLen = 1e9
        count, sIndex = 0, -1
        charsDict = defaultdict(int)

        # Only characters in string t will have positive values
        for ch in t:
            charsDict[ch] += 1
        
        while r < len(s):
            # If positive value means pre-inserted (part of t hence increase count)
            if charsDict[s[r]] > 0:
                count += 1
            charsDict[s[r]] -= 1

            # Shrinking Phase to get the minimum window if count == size of t
            while count == len(t):
                if (r-l+1 < minLen):
                    minLen = r-l+1
                    sIndex = l

                charsDict[s[l]] += 1
                # If the left element count in dictionary > 0 means it was preinserted and means the count is now reduced
                if charsDict[s[l]] > 0:
                    count -= 1
                l += 1

            r += 1

        return "" if minLen==1e9 else s[sIndex:sIndex+minLen]
