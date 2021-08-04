# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode):
        ans = []
        def pTra(node):
            if node is None:
                return node
            pTra(node.left)
            pTra(node.right)
            ans.append(node.val)
        pTra(root)
        return ans