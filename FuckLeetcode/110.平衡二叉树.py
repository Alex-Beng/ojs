#
# @lc app=leetcode.cn id=110 lang=python3
#
# [110] 平衡二叉树
#

from util import TreeNode
# @lc code=start
from functools import lru_cache
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        @lru_cache(None)
        def height(node):
            if node is None:
                return 0
            t = height(node.left)
            t = max(t, height(node.right))
            return t+1
        height(root)

        def dfs(node):
            if node is None:
                return True
            l = height(node.left)
            r = height(node.right)
            if abs(l-r) > 1:
                return False
            else:
                return dfs(node.left) and dfs(node.right)
        return dfs(root)
# @lc code=end

