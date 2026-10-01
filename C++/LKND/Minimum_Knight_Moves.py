from collections import deque
from typing import Set, Tuple

class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        # Initialize BFS queue with starting position (0, 0)
        queue = deque([(0, 0)])
        moves = 0
        visited: Set[Tuple[int, int]] = {(0, 0)}

        # All 8 possible knight moves: 2 squares in one direction, 1 square perpendicular
        knight_directions = (
            (-2, 1), (-1, 2), (1, 2), (2, 1),
            (2, -1), (1, -2), (-1, -2), (-2, -1)
        )

        while queue:
            level_size = len(queue)

            for _ in range(level_size):
                current_x, current_y = queue.popleft()
                if (current_x, current_y) == (x, y):
                    return moves

                for dx, dy in knight_directions:
                    next_x = current_x + dx
                    next_y = current_y + dy
                    if (next_x, next_y) not in visited:
                        visited.add((next_x, next_y))
                        queue.append((next_x, next_y))
            moves += 1
        return -1
