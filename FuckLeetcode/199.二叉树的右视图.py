#
# @lc app=leetcode.cn id=199 lang=python3
#
# [199] 二叉树的右视图
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> [int]:
        ans = []
        def caoOrder(nodes):
            ans.append(nodes[-1].val)
            nnodes = []
            for node in nodes:
                if node.left is not None:
                    nnodes.append(node.left)
                if node.right is not None:
                    nnodes.append(node.right)
            if len(nnodes):
                caoOrder(nnodes)
        if not root:
            return []
        caoOrder([root])
        return ans

# @lc code=end

