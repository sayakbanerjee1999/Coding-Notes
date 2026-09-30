class Solution:
    def checkValidString(self, s: str) -> bool:
        # "*" can be -1 ')', 0 '', 1 '('
        min_ = 0
        max_ = 0

        for chr in s:
            if chr == "(":
                min_ += 1
                max_ += 1
            elif chr == ")":
                min_ -= 1
                max_ -= 1
            else:
                min_ -= 1
                max_ += 1
            
            if min_ < 0:
                min_ = 0
            if max_ < 0:
                return False
        
        return min_==0
