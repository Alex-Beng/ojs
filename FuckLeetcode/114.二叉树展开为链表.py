from util import TreeNode

class Solution:
    def flatten(self, root: TreeNode) -> None:

        def expan(node: TreeNode):
            if node.left is None and node.right is None:
                return node
            if node.left is None:
                return expan(node.right)
            if node.right is None:
                ltail = expan(node.left)
                node.right = node.left
                node.left = None
                return ltail
            
            ltail = expan(node.left)
            l = node.left
            r = node.right
            node.left = None
            node.right = l
            ltail.right = r

            rtail = expan(r)
            return rtail
        if root is None:
            return None
        expan(root)
        return root
            
            
            
