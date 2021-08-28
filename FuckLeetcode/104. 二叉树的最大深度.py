from util import *
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        ans = [0]
        def m_d(layer, node):
            if node is None:
                ans[0] = max(layer, ans[0])
                return
            m_d(layer+1, node.left)
            m_d(layer+1, node.right)
        m_d(0, root)
        return ans[0]