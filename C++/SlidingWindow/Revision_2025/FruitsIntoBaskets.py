from collections import defaultdict

class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        k = 2
        fruitTypes = defaultdict(int)

        l, r, maxLen = 0, 0, 0

        while r < len(fruits):
            fruitTypes[fruits[r]] += 1
            
            # Replace while with if
            if len(fruitTypes) > k:
                fruitTypes[fruits[l]] -= 1
                if fruitTypes[fruits[l]] == 0:
                    del fruitTypes[fruits[l]]
                l += 1
            
            if len(fruitTypes) <= k:
                maxLen = max(maxLen, r-l+1)
            
            r += 1
        
        return maxLen 

        
