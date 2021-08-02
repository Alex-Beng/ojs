# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        def in_trav(node):
            if node is None:
                return
            in_trav(node.left)
            ans.append(node.val)
            in_trav(node.right)
        in_trav(root)
        return ans