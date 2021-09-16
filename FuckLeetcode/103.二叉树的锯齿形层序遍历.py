#
# @lc app=leetcode.cn id=103 lang=python3
#
# [103] 二叉树的锯齿形层序遍历
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> [[int]]:
        if not root:
            return []
        ans = []
        def zzOrder(nodes: [TreeNode], l2r: bool):
            n = len(nodes)
            # print(n, l2r)
            if l2r:
                b, e, s = 0, n, 1
            else:
                b, e, s = n-1, -1, -1
            t_ans = []
            nnodes = []
            for i in range(b,e,s):
                node = nodes[i]
                t_ans.append(node.val)

                if not l2r:
                    if node.right is not None:
                        nnodes = [node.right] + nnodes
                    if node.left is not None:
                        nnodes = [node.left] + nnodes
                else:
                    if node.left is not None:
                        nnodes.append(node.left)
                    if node.right is not None:
                        nnodes.append(node.right)
                    
            ans.append(t_ans)
            if len(nnodes):
                zzOrder(nnodes, not l2r)
        zzOrder([root], True)
        return ans
# @lc code=end

