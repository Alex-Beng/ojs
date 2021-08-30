from util import *

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None:
            root = TreeNode(val)

        if root.val < val:
            if root.right is None:
                # insert
                new_node = TreeNode(val)
                root.right = new_node
            else:
                self.insertIntoBST(root.right, val)
        elif root.val > val:
            if root.left is None:
                # insert
                new_node = TreeNode(val)
                root.left = new_node
            else:
                self.insertIntoBST(root.left, val)

        return root