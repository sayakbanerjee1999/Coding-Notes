from collections import defaultdict

class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        
        # Create the Adjacency List
        adj = defaultdict(list)
        for person_a, person_b in dislikes:
            adj[person_a].append(person_b)
            adj[person_b].append(person_a)

        # (n+1) -> since 1-indexed
        color = [-1] * (n + 1)
        flag = 0

        def dfs(src, par, col):
            nonlocal flag

            color[src] = col

            for nei in adj[src]:
                # If not colored -> color with opposite color
                if color[nei] == -1:
                    dfs(nei, src, 3 - col)
                # If it is already colored
                # If this is not my parent and my neighbor has the same color as me, we found a conflict.
                # elif nei != par and color[nei] == col:
                # The parent condition to check is actually redundant but its common practice to check
                # Because we do not want to go back to the node we already visited
                elif color[nei] == col:
                    flag = 1
                    return

        # Start from different vertices
        for i in range(1, n + 1):
            if color[i] == -1:
                dfs(i, -1, 1)

        return flag == 0
        
