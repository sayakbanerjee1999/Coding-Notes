from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        p_dict = dict(Counter(p))
        s_dict = {}
        if len(s) < len(p):
            return []
        
        res = []
        i, j = 0, 0
        k = len(p)

        while i < len(s):
            # Use character as key
            if s[i] not in s_dict:
                s_dict[s[i]] = 1
            else:
                s_dict[s[i]] += 1

            if i-j+1 > k:
                s_dict[s[j]] -= 1
                if s_dict[s[j]] == 0:
                    del s_dict[s[j]]
                j += 1

            if i-j+1 == k:
                if s_dict == p_dict:
                    res.append(j)

            i += 1

        return res
            
        
