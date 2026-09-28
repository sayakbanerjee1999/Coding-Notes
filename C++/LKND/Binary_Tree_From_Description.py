from typing import List, Optional
from collections import defaultdict

class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        # Dictionary to store all nodes by their values
        nodes = {}
        children = set()
      
        for parent_val, child_val, is_left in descriptions:
            # Create parent node if it doesn't exist
            if parent_val not in nodes:
                nodes[parent_val] = TreeNode(parent_val)
            # Create child node if it doesn't exist
            if child_val not in nodes:
                nodes[child_val] = TreeNode(child_val)
          
            # Track this node as a child (cannot be root)
            children.add(child_val)
            # Attach child to parent's left or right based on is_left flag
            if is_left:
                nodes[parent_val].left = nodes[child_val]
            else:
                nodes[parent_val].right = nodes[child_val]
      
        # Find root node: the only node that appears as parent but never as child
        # Get the difference between all nodes and child nodes
        root_val = (set(nodes.keys()) - children).pop()
      
        # Return the root node
        return nodes[root_val]
