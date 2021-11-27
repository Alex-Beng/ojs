#
# @lc app=leetcode.cn id=337 lang=python3
#
# [337] 打家劫舍 III
#
from util import TreeNode
# @lc code=start
from functools import lru_cache
class Solution:
    def rob(self, root: TreeNode) -> int:
        nums = []
        @lru_cache(None)
        def dfs(node: TreeNode, can: bool) -> int:
            if node is None:
                return 0
            node_sum = 0
            if can:
                t_sum = node.val
                t_sum += dfs(node.left, False)
                t_sum += dfs(node.right, False)
                node_sum = t_sum
            t_sum = 0
            t_sum += dfs(node.left, True)
            t_sum += dfs(node.right, True)
            node_sum = max(node_sum, t_sum)
            return node_sum
        return dfs(root, True)
# @lc code=end