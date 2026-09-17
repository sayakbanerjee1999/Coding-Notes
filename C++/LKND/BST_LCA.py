# Node structure
# class Node:
#     def __init__(self, val):
#         self.data = val
#         self.left = None
#         self.right = None


def findLCA(root, n1, n2):
    if root is None:
        return None

    # If both n1 and n2 are smaller than root, 
    # go to left subtree
    if root.data > n1.data and root.data > n2.data:
        return findLCA(root.left, n1, n2)

    # If both n1 and n2 are greater than root, 
    # go to right subtree
    if root.data < n1.data and root.data < n2.data:
        return findLCA(root.right, n1, n2)

    # If nodes n1 and n2 are on the opposite sides, 
    # root is the LCA
    return root
