#
# @lc app=leetcode.cn id=230 lang=python3
#
# [230] 二叉搜索树中第K小的元素
#
from util import TreeNode
# @lc code=start

from functools import lru_cache
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        @lru_cache(None)
        def subNum(node: TreeNode):
            if node is None:
                return 0
            if node.left is None and node.right is None:
                return 1
            return 1+subNum(node.right)+subNum(node.left)
        def search(node: TreeNode, k):
            tk = subNum(node.left)+1
            if tk == k:
                return node.val
            elif tk < k:
                return search(node.right, k-tk)
            else:
                return search(node.left, k)
        return search(root, k)
# @lc code=end

