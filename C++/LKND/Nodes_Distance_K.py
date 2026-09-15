# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque, defaultdict

class Solution:
    def parentMapF(self, root):
        parentMap = {}
        q = deque([root])
        while q:
            currNode = q.popleft()
            if currNode.left:
                parentMap[currNode.left] = currNode
                q.append(currNode.left)
            if currNode.right:
                parentMap[currNode.right] = currNode
                q.append(currNode.right)

        return parentMap

    def distanceK(self, root, target, k):
        res = []
        visited = set()

        # Get Parent so that you can travel up the tree as well
        parentMap = self.parentMapF(root)

        q = deque([target])
        visited.add(target)
        currLevel = 0
        while q:
            size = len(q)
            if currLevel == k:
                break
            for _ in range(size):
                currNode = q.popleft()
                if currNode.left and currNode.left not in visited:
                    visited.add(currNode.left)
                    q.append(currNode.left)
                if currNode.right and currNode.right not in visited:
                    visited.add(currNode.right)
                    q.append(currNode.right)
                # Get the Parent as well -> move up
                parent = parentMap.get(currNode)
                if parent and parent not in visited:
                    visited.add(parent)
                    q.append(parent)

            currLevel += 1

        # Get the nodes at distance k
        while q:
            node = q.popleft()
            res.append(node.val)

        return res
        
