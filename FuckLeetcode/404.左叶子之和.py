#
# @lc app=leetcode.cn id=404 lang=python3
#
# [404] 左叶子之和
#

from util import TreeNode
# @lc code=start
from functools import lru_cache
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ans = 0
        @lru_cache(None)
        def isLeaf(node: TreeNode):
            if node is None:
                return False
            return node.left is None and node.right is None
        def dfs(node: TreeNode):
            nonlocal ans
            if node is None:
                return
            if isLeaf(node.left):
                ans += node.left.val
                dfs(node.right)
                return 
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return ans
# @lc code=end

t = TreeNode(2)
tt = TreeNode(1)
tt.left = t
s = Solution()
r = s.sumOfLeftLeaves(tt)
print(r)
