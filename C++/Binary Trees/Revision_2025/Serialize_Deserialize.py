from queue import Queue
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return ""
        
        tree_str = ""

        q = Queue()
        q.put(root)

        # Doing a kind-off preorder traversal
        # If null on the left / right -> specifically add "#"
        while not q.empty():
            currNode = q.get()
            
            if currNode is None:
                tree_str += "#,"
            else:
                tree_str += str(currNode.val) + ","

                q.put(currNode.left)
                q.put(currNode.right)
        
        return tree_str


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if not data:
            return None

        tokens = data.split(",")[:-1]
        
        root_val = int(tokens.pop(0))
        root = TreeNode(root_val)

        q = Queue()
        q.put(root)

        while not q.empty():
            node = q.get()

            left_val = tokens.pop(0)
            if left_val != "#":
                left_node = TreeNode(left_val)
                q.put(left_node)
                node.left = left_node
            
            right_val = tokens.pop(0)
            if right_val != "#":
                right_node = TreeNode(right_val)
                q.put(right_node)
                node.right = right_node
        
        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
