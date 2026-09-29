class Solution:
    def __init__(self):
        self.dx = [-1, 0, 1, 0]
        self.dy = [0, 1, 0, -1]

    def dfsHelper(self, i: int, j: int, n: int, m: int,
                grid: list[list[int]], visited: list[list[int]]):
        visited[i][j] = 1
        area = 1

        for k in range(4):
            new_x = i + self.dx[k]
            new_y = j + self.dy[k]

            if new_x >= 0 and new_x < n and new_y >= 0 and new_y < m and not visited[new_x][new_y] and grid[new_x][new_y] == 1:
                area += self.dfsHelper(new_x, new_y, n, m, grid, visited)
        
        return area


    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        n, m = len(grid), len(grid[0])
        visited = [[False for _ in range(m)] for _ in range(n)]
        
        maxArea = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and not visited[i][j]:
                    area = self.dfsHelper(i, j, n, m, grid, visited)
                    maxArea = max(area, maxArea)

        return maxArea
