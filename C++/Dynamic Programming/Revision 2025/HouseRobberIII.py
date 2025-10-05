# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        
        # [Always return the value - [WithNode, WithoutNode]]
        def dfs(root):
            if root is None:
                return [0, 0]
            
            leftPair = dfs(root.left)       #[withLeftNode, withoutLeftNode]
            rightPair = dfs(root.right)     #[wightRightNode, withoutRightNode]

            # If root is include we can only take without values from left and right
            withRoot = root.val + leftPair[1] + rightPair[1]

            # If root is not included. There is no restriction now.
            # Take the max from left and right
            withoutRoot = max(leftPair) + max(rightPair)

            return [withRoot, withoutRoot]
        
        withRoot, withoutRoot = dfs(root)
        return max(withRoot, withoutRoot)
        
