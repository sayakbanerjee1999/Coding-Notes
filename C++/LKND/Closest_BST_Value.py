from typing import Optional
from math import inf

# Closest Node to Target -
# If current value > target. Move left -> left has smaller
# Else move right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        def dfs(node: Optional[TreeNode]) -> None:
            # Base case: reached a null node
            if node is None:
                return

            # Calculate the absolute difference between current node value and target
            current_difference = abs(target - node.val)

            # Access the outer scope variables
            nonlocal closest_value, min_difference

            # Update the closest value if:
            # 1. Current difference is smaller than the minimum found so far, OR
            # 2. Difference is the same but current value is smaller (tiebreaker)
            if current_difference < min_difference or \
               (current_difference == min_difference and node.val < closest_value):
                min_difference = current_difference
                closest_value = node.val

            # Leverage BST property: go left if target is smaller, right otherwise
            # This ensures we explore the most promising path
            if target < node.val:
                next_node = node.left
            else:
                next_node = node.right

            # Continue searching in the chosen direction
            dfs(next_node)

        # Initialize variables to track the closest value and its difference
        closest_value = 0  # Will be updated during traversal
        min_difference = inf  # Start with infinity to ensure first node updates it

        # Start the depth-first search from root
        dfs(root)

        return closest_value
