# Node-level BFS  → store t with each node
# Level-level BFS → increment time after each level

# visited[i][j] = 2 simply means “this orange/cell has already been processed 
# or is already rotten.” We use it to prevent the same fresh orange from being 
# added to the queue multiple times by different rotten neighbors.

from collections import deque

class Solution:
    def orangesRotting(self, grid):
        n = len(grid)
        m = len(grid[0])

        visited = [[0] * m for _ in range(n)]

        q = deque()

        # Add all initially rotten oranges
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2 and visited[i][j] == 0:
                    q.append((i, j, 0))
                    visited[i][j] = 2

        deltaRow = [-1, 0, 1, 0]
        deltaCol = [0, 1, 0, -1]

        time = 0

        while q:
            x, y, t = q.popleft()

            time = max(t, time)

            # Check 4 directions
            for i in range(4):
                row = x + deltaRow[i]
                col = y + deltaCol[i]

                if (0 <= row < n and 
                    0 <= col < m and 
                    visited[row][col] != 2 and 
                    grid[row][col] == 1):

                    q.append((row, col, time + 1))
                    visited[row][col] = 2

        # Check if any fresh orange remains
        for i in range(n):
            for j in range(m):
                if visited[i][j] != 2 and grid[i][j] == 1:
                    return -1

        return time
