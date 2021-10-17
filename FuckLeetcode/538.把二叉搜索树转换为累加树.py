#
# @lc app=leetcode.cn id=538 lang=python3
#
# [538] 把二叉搜索树转换为累加树
#

from util import TreeNode

# @lc code=start

class Solution:
    def convertBST(self, root: TreeNode) -> TreeNode:
        accu_sum = 0
        def mid_ord(node: TreeNode) -> int:
            nonlocal accu_sum
            if node is None:
                return 

            mid_ord(node.right)
            accu_sum += node.val
            node.val = accu_sum
            mid_ord(node.left)
        mid_ord(root)
        return root

# @lc code=end

