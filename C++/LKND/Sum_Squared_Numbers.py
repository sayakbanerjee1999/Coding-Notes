class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        # Bounds 
        a = 0
        b = int(math.sqrt(c))

        while a <= b:
            if (a*a + b*b) == c:
                return True
            
            # Small is smaller; b is already at maximum so increase a
            elif (a*a + b*b) < c:
                a += 1
            else:
                b -= 1
        
        return False
