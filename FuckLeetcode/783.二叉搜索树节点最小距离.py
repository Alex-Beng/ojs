#
# @lc app=leetcode.cn id=783 lang=python3
#
# [783] 二叉搜索树节点最小距离
#
from util import TreeNode
# @lc code=start
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        last_vis = -1
        ans = float('inf')
        def mord(node: TreeNode):
            nonlocal last_vis,ans
            if node is None:
                return
            mord(node.left)
            if last_vis!=-1 and abs(node.val-last_vis)<ans:
                ans = min(ans, abs(node.val-last_vis))
            last_vis = node.val
            mord(node.right)
        mord(root)
        return ans
# @lc code=end