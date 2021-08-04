# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def preorderTraversal(self, root: TreeNode):
        ans = []
        def pTrav(node):
            if node is None:
                return
            # print(node.val)
            ans.append(node.val)
            pTrav(node.left)
            pTrav(node.right)
        pTrav(root)
        return ans
        
r = TreeNode(1)
n1 = TreeNode(2)
n2 = TreeNode(3)

r.right = n1
n1.left = n2

s = Solution()
print(s.preorderTraversal(r))
