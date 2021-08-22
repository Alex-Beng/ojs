# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def check(node, left_bound, right_bound):
            if node is None:
                return True
            if left_bound<node.val and node.val<right_bound:
                return check(node.left, left_bound, node.val) and check(node.right, node.val, right_bound)
            else:
                return False
        return check(root, float('-inf'), float('inf'))
    