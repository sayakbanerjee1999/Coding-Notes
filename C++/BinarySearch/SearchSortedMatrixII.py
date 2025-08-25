class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # We observe that the rightmost-top and leftmost-bottom cells are the only startable positions 
        # (to the left smaller, to the right bigger). So we can eliminate one half. Effective as in binary search 
        # Next we see that if that target is bigger than where we are currently - we need to traverse down (bigger elements). 
        # Otherwise we move to the left (smaller elements)
        nrow = 0
        ncol = len(matrix[0]) - 1

        # Make sure you stay in bounds
        while nrow >= 0 and nrow < len(matrix) and ncol < len(matrix[0]) and ncol >= 0:
            if matrix[nrow][ncol] == target:
                return True
            
            elif matrix[nrow][ncol] > target:
                ncol -= 1
            else:
                nrow += 1
        

        return False
