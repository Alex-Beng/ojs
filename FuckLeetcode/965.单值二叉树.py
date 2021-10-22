#
# @lc app=leetcode.cn id=965 lang=python3
#
# [965] 单值二叉树
#
from util import TreeNode
# @lc code=start

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        ans = True
        v = root.val
        def isU(node: TreeNode):
            nonlocal ans, v
            if node is None:
                return
            if node.val == v:
                isU(node.left)
                isU(node.right)
            else:
                ans = False
                return
        isU(root)
        return ans
# @lc code=end

