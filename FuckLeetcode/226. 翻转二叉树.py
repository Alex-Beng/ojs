from util import *
class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:

        def invert(node):
            if node is None:
                return
            if node.left is None and node.right is None:
                return
            
            invert(node.left)
            invert(node.right)
            node.left, node.right = node.right, node.left
        invert(root)
        return root