#
# @lc app=leetcode.cn id=105 lang=python3
#
# [105] 从前序与中序遍历序列构造二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: [int], inorder: [int]) -> TreeNode:
        inn = len(inorder)
        if inn == 0:
            return None
        elif inn == 1:
            return TreeNode(inorder[0])

        root = TreeNode(preorder[0])
        
        left = []
        # right = []
        cnt = 0
        while inorder[cnt] != preorder[0]:
            left.append(inorder[cnt])
            cnt += 1
        right = inorder[cnt+1:]
        root.left = self.buildTree(preorder[1:], left)
        root.right = self.buildTree(preorder[1+cnt:], right)
        return root
        

# @lc code=end

