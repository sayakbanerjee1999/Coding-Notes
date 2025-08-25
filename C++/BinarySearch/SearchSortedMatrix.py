class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        nrows = len(matrix)
        ncols = len(matrix[0])

        lo = 0
        hi = nrows * ncols - 1          # Number of elements - 1

        while lo <= hi:
            mid = lo + (hi - lo) // 2
            
            # Convert 1d array index to matrix
            row = mid // ncols
            col = mid % ncols
            
            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                hi = mid - 1
            else:
                lo = mid + 1
        
        return False
        
