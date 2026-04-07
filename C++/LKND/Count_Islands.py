class Solution:
    def __init__(self):
        self.dx = [-1, 0, 1, 0]
        self.dy = [0, 1, 0, -1]

    def dfs(self, i: int, j: int, m: int, n: int, 
            grid: List[List[str]], visited: List[List[bool]]) -> None:
        visited[i][j] = 1

        for k in range(4):
            new_x = i + self.dx[k]
            new_y = j + self.dy[k]

            if (new_x >= 0 and new_x < m and new_y >= 0 and new_y < n and 
            not visited[new_x][new_y] and grid[new_x][new_y] == "1"):
                self.dfs(new_x, new_y, m, n, grid, visited)

    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        visited = [[0 for _ in range(n)] for _ in range(m)]

        islands = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1' and not visited[i][j]:
                    self.dfs(i, j, m, n, grid, visited)
                    islands += 1
        
        return islands
