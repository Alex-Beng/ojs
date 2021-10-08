from util import TreeNode

class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        last = float('-inf')
        min_diff = float('inf')
        def mord(node: TreeNode):
            nonlocal last, min_diff
            if node is None:
                return
            mord(node.left)
            t = abs(node.val-last)
            if t < min_diff:
                min_diff = t
            last = node.val
            mord(node.right)
        mord(root)
        return min_diff
            