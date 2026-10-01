from collections import defaultdict, deque
from typing import Optional

class Solution:
    def findClosestLeaf(self, root: Optional[TreeNode], k: int) -> int:
        def build_graph(node: Optional[TreeNode], parent: Optional[TreeNode]) -> None:
            if node:
                graph[node].append(parent)
                graph[parent].append(node)

                build_graph(node.left, node)
                build_graph(node.right, node)

        graph = defaultdict(list)
        build_graph(root, None)

        # Find the starting node with value k and initialize BFS queue
        queue = deque(node for node in graph if node and node.val == k)

        visited = set(queue)
        while True:
            current_node = queue.popleft()
            if current_node:
                if current_node.left == current_node.right:  # Both are None
                    return current_node.val

                for neighbor in graph[current_node]:
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)
