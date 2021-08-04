class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        ans = [float('inf')]
        def m_d(layer, node):
            if node is None:
                return
            if node.left is None and node.right is None:
                ans[0] = min(layer+1, ans[0])
            m_d(layer+1, node.left)
            m_d(layer+1, node.right)
        m_d(0, root)
        return ans[0]