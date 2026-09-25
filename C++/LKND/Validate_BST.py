# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Remember that left side values are smaller than right values
# Pass Min and Max values
# If current node value <= min allowed value or >= max allowed value -> BST condition violated

class Solution:
    def isValidBST(self, root: TreeNode | None) -> bool:
        
        def helperBST(node, min_val, max_val):
            if node == None:
                return True
            
            if node.val <= min_val or node.val >= max_val:
                return False

            return (helperBST(node.left, min_val, node.val) and 
                    helperBST(node.right, node.val, max_val))

        return helperBST(root, float('-inf'), float('inf'))
