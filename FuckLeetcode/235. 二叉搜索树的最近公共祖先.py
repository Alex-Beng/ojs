from util import *
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:

        def dfs(node: TreeNode):
            # all in left sub tree
            if p.val < node.val and q.val < node.val:
                return dfs(node.left)
            # all in right sub tree
            if p.val > node.val and q.val > node.val:
                return dfs(node.right)
            # one left, one right
            if p.val >= node.val and q.val <= node.val \
                or p.val <= node.val and q.val >= node.val:
                return node
        return dfs(root)
        