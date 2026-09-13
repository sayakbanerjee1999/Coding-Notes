# For example, if you have a tree like:


# Copy
#       1
#      / \
#     2   3
#    / \
#   4   5
# The collection process would be:

# First iteration: Collect leaves [4, 5, 3] and remove them
# Second iteration: Now 2 is a leaf, collect [2] and remove it
# Third iteration: Now 1 is a leaf, collect [1] and remove it
# The final output would be: [[4, 5, 3], [2], [1]]

# POST ORDER DFS

# The key insight is recognizing that we don't actually need to simulate the removal process. 
# Instead, we can think about when each node would be removed based on its position in the tree.

# Consider what makes a node removable at each step - it must be a leaf node. 
# Initially, only the actual leaf nodes can be removed. After removing them, their parent nodes 
# might become new leaves if they have no other children. This pattern continues until we reach the root.

# Instead of repeatedly finding and removing leaves (which would be inefficient), we can calculate 
# each node's height from the bottom in a single DFS traversal. 
# The height of any node is simply 1 + max(height of left child, height of right child). 
# For null nodes, we return height -1, so leaf nodes correctly get height 0.

# During the DFS traversal, as we calculate each node's height, we can directly place it into the appropriate 
# group in our result. All nodes with the same height will be removed together in the same iteration, 
# so they belong in the same sublist.


from typing import Optional, List

class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        def calculate_height_and_collect(node: Optional[TreeNode]) -> int:
            # Base case: empty node has height -1
            if node is None:
                return -1

            # Recursively calculate heights of left and right subtrees
            left_height = calculate_height_and_collect(node.left)
            right_height = calculate_height_and_collect(node.right)

            # Current node's height is max of children's heights plus 1
            current_height = max(left_height, right_height) + 1

            # Ensure result list has enough sublists for this height level
            if len(result) == current_height:
                result.append([])

            # Add current node's value to its corresponding height group
            result[current_height].append(node.val)

            # Return current node's height for parent's calculation
            return current_height

        # Initialize result list to store nodes grouped by height
        result = []

        # Start DFS traversal from root
        calculate_height_and_collect(root)

        return result
