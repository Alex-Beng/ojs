#
# @lc app=leetcode.cn id=108 lang=python3
#
# [108] 将有序数组转换为二叉搜索树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        n = len(nums)
        if n==0:
            return None
        elif n==1:
            return TreeNode(nums[0])
        elif n==2:
            root = TreeNode(nums[1])
            root.left = TreeNode(nums[0])
            return root
        elif n==3:
            root = TreeNode(nums[1])
            root.left = TreeNode(nums[0])
            root.right = TreeNode(nums[2])
            return root

        mid = n//2
        print(mid)

        left = nums[:mid]
        right = nums[mid+1:]
        print(left, right)
        
        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(left)
        root.right = self.sortedArrayToBST(right)

        return root

# @lc code=end

