class Solution:
    def checkValidString(self, s: str) -> bool:
        # "*" can be -1 ')', 0 '', 1 '('
        min_ = 0
        max_ = 0

        for chr in s:
            # If "(" mandatorily add 1 from both ranges
            if chr == "(":
                min_ += 1
                max_ += 1
            # If ")" mandatorily subtract 1 from both ranges
            elif chr == ")":
                min_ -= 1
                max_ -= 1
            # If "*", we can have ")" -1, "" 0, "(" +1
            # So add +1 to the max range and subtract -1 from the minimum
            else:
                min_ -= 1
                max_ += 1
            
            # We will never allow min to go below 0 
            if min_ < 0:
                min_ = 0
            # Iff max anytime goes below 0 we know that this is not allowed
            if max_ < 0:
                return False
        
        return min_==0
