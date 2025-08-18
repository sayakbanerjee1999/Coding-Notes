from collections import defaultdict

class Solution:
    # Suppose k = 2 AAAABDD. When you are at the 2nd D the max_freq = 4 and length = 7. 
    # At all times you want to make sure length - max_frequency <= k. As soon as it is > k you would want to 
    # shrink your window by moving l to the right by 1 place
    def characterReplacement(self, s: str, k: int) -> int:
        l, r, maxLen = 0, 0, 0
        charsDict = defaultdict(int)

        while r < len(s):
            charsDict[s[r]] += 1
            maxFreq = max(fr for fr in charsDict.values())
            
            while (r-l+1) - maxFreq > k:
                charsDict[s[l]] -= 1
                if charsDict[s[l]] == 0:
                    del charsDict[s[l]]
                # maxFreq = max(fr for fr in charsDict.values())        # This is redundant
                l += 1

            if (r-l+1) - maxFreq <= k:
                maxLen = max(maxLen, r-l+1)
            
            r += 1
        
        return maxLen
