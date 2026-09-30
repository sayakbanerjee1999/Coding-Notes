class Solution:
    def hasPath(self, maze: List[List[int]], start: List[int], destination: List[int]) -> bool:
        rows = len(maze)
        cols = len(maze[0])

        # Track positions where the ball has already STOPPED.
        visited = [[False] * cols for _ in range(rows)]

        # Four possible directions: up, right, down, left.
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]

        def dfs(row, col):
            # If we've already explored this stopping position, there is no need to explore it again.
            if visited[row][col]:
                return False

            # If the ball stopped at the destination, we're done.
            if [row, col] == destination:
                return True

            # Mark this stopping position as explored.
            visited[row][col] = True

            # Try rolling in all four directions.
            for k in range(4):

                # Start rolling from the current stopping position.
                next_row, next_col = row, col

                # Keep rolling while the NEXT cell:
                while (
                    0 <= next_row + dx[k] < rows
                    and 0 <= next_col + dy[k] < cols
                    and maze[next_row + dx[k]][next_col + dy[k]] == 0
                ):
                    # Move one step in the current direction.
                    next_row += dx[k]
                    next_col += dy[k]

                # The ball has now stopped because the next cell
                # is either a wall or outside the maze.
                # Explore from this new stopping position.
                if dfs(next_row, next_col):
                    return True

            # None of the four directions can eventually
            # reach the destination.
            return False

        # Start DFS from the starting position.
        return dfs(start[0], start[1])
