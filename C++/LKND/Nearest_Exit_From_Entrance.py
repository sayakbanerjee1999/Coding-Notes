from collections import deque

class Solution:
    def __init__(self):
        self.dx = [-1, 0, 1, 0]
        self.dy = [0, 1, 0, -1]

    def nearestExit(self, maze: list[list[str]], entrance: list[int]) -> int:
        m, n = len(maze), len(maze[0])
        steps = 0

        # Not carrying a separate visited dictionary; if visited; will turn it in + to avoid loops
        start, end = entrance
        q = deque([[start, end]])

        # So convert this position into a wall; to avoid loops
        maze[start][end] = '+'

        while q:
            steps += 1

            # Explore all nodes at the current level simultaneously
            for _ in range(len(q)):
                # curr_ele = q.popleft()
                # curr_x, curr_y = curr_ele[0], curr_ele[1]
                curr_x, curr_y = q.popleft()

                for k in range(4):
                    next_x = curr_x + self.dx[k]
                    next_y = curr_y + self.dy[k]

                    # If next cell is empty
                    if next_x >= 0 and next_x < m and next_y >= 0 and next_y < n and maze[next_x][next_y] == '.':
                        # If next cell is on the boundary
                        if next_x == 0 or next_x == m-1 or next_y == 0 or next_y == n-1:
                            return steps
                        
                        # Else add to q and mark visited
                        maze[next_x][next_y] = '+'
                        q.append([next_x, next_y])
        
        return -1
