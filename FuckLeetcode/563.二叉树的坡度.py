from util import TreeNode

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        ans = 0
        def pord(node: TreeNode) -> int:
            nonlocal ans
            if node is None:
                return 0
            l = pord(node.left)
            r = pord(node.right)
            ans += abs(l-r)
            return l+r+node.val
        pord(root)
        return ans