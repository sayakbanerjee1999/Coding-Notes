class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        open = 0
        close = 0

        for ch in s:
            if ch == "(":
                open += 1
            else:
                # If opening bracket present reduce it
                if open > 0:
                    open -= 1
                # If opening brack not present then increase the requirement of closing brackets
                else:
                    close += 1
        
        return open + close
