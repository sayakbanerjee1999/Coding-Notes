# Algorithm Steps:
# 1. Initialize the deque: Create an empty deque q that will store up to k values.

# 2. Perform in-order DFS traversal: The dfs function recursively traverses the tree:
# dfs(root.left)  # Visit left subtree first
# # Process current node
# dfs(root.right) # Visit right subtree last

# 3.Process each node during traversal:
# If deque has less than k elements: Simply append the current value
# if len(q) < k:
#     q.append(root.val)
# If deque is full (has k elements):
#   Compare the distance of the current value with the leftmost value in deque
#   Since we're traversing in ascending order, the leftmost value is the smallest
#   If abs(root.val - target) >= abs(q[0] - target), we can stop early because:
#   The current value is farther from target than our worst candidate (leftmost element in the queue)
#   All subsequent values (being larger) will be even farther.
#   <THIS IS THE EARLY TERMINATION OPTIMIZATION>
#   Otherwise, slide the window:

# q.popleft()      # Remove the farthest value (leftmost)
# q.append(root.val)  # Add the closer value


class Solution:
    def closestKValues(self, root: Optional[TreeNode], target: float, k: int) -> List[int]:
        def inorder_traverse(node: Optional[TreeNode]) -> None:
            if node is None:
                return

            # Traverse left subtree first (smaller values in BST)
            inorder_traverse(node.left)

            # Process current node
            if len(closest_values_queue) < k:
                # Queue not full yet, add current value
                closest_values_queue.append(node.val)
            else:
                # Queue is full, check if current value is closer than the first value in queue
                # Since we're doing in-order traversal, values are processed in ascending order
                # The first element in queue is the smallest and potentially furthest from target
                if abs(node.val - target) >= abs(closest_values_queue[0] - target):
                    # EARLY TERMINATION
                    return

                # Current value is closer, remove the furthest and add current
                closest_values_queue.popleft()
                closest_values_queue.append(node.val)

            # Traverse right subtree (larger values in BST)
            inorder_traverse(node.right)

        closest_values_queue = deque()
        inorder_traverse(root)
        return list(closest_values_queue)
