# When a repeated character is found inside the current window (charsDict[ch] >= l), 
# l is moved to one position after its previous occurrence. At each step, maxWindow 
# records the maximum window length seen so far. This gives O(n) time and O(k) space, 
# where k is the number of distinct characters.

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r, maxWindow = 0, 0, 0
        charsDict = defaultdict(int)

        for idx, ch in enumerate(s):
            if ch in charsDict and charsDict[ch] >= l:
                l = charsDict[ch] + 1
            
            maxWindow = max(maxWindow, r-l+1)
            charsDict[ch] = r
            r += 1
        
        return maxWindow
