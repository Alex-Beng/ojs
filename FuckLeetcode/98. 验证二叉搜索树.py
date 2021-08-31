from util import *
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
    