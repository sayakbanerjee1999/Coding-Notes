class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(s) < len(p):
            return []

        res = []
        window_dict = defaultdict(int)
        p_dict = defaultdict(int)

        for ch in p:
            p_dict[ch] += 1
        
        l, r = 0, 0
        while r < len(s):
            window_dict[s[r]] += 1

            if r - l + 1 < len(p):
                r += 1
            
            elif r - l + 1 == len(p):
                if window_dict == p_dict:
                    res.append(l)
                
                window_dict[s[l]] -= 1
                if window_dict[s[l]] == 0:
                    del window_dict[s[l]]
                
                l += 1
                r += 1

        return res
