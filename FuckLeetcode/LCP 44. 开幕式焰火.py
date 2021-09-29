from util import TreeNode

class Solution:
    def numColor(self, root: TreeNode) -> int:
        ans = set()
        def dfs(node):
            if node is None:
                return
            ans.add(node.val)
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return len(ans)