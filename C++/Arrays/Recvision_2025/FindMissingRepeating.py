class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        size = n*n

        expected_sum = size * (size + 1)//2
        expected_sum_squares = size * (size + 1) * (2*size + 1)//6

        actual_sum = 0
        actual_sum_squares = 0
        for i in range(n):
            for j in range(n):
                actual_sum += grid[i][j]
                actual_sum_squares += grid[i][j]*grid[i][j]
        
        a_plus_b = (actual_sum_squares - expected_sum_squares) // (actual_sum - expected_sum)
        a_minus_b = (actual_sum - expected_sum)

        a = (a_plus_b + a_minus_b) // 2
        b = (a_plus_b - a_minus_b) // 2

        return [a, b]
