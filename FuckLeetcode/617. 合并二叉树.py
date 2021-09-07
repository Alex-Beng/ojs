from util import *
class Solution:
    def mergeTrees(self, root1: TreeNode, root2: TreeNode) -> TreeNode:

        def merge(r1: TreeNode, r2: TreeNode) -> TreeNode:
            if r1 is None and r2 is None:
                return None
            ans = TreeNode(0)
            if r1 is not None:
                ans.val += r1.val
            if r2 is not None:
                ans.val += r2.val
            
            if r1 is not None and r2 is not None:
                ans.left = merge(r1.left, r2.left)
                ans.right = merge(r1.right, r2.right)
            elif r1 is None:
                ans.left = merge(None, r2.left)
                ans.right = merge(None, r2.right)
            elif r2 is None:
                ans.left = merge(r1.left, None)
                ans.right = merge(r1.right, None)
                
            
            return ans
        return merge(root1, root2)

        
            