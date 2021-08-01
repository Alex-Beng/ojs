# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def getTargetCopy(self, original: TreeNode, cloned: TreeNode, target: TreeNode) -> TreeNode:
        org2clo = dict()
        def m_visit(org, clo):
            if org is None:
                return
            m_visit(org.left, clo.left)
            org2clo[org] = clo
            m_visit(org.right, clo.right)
        m_visit(original, cloned)
        return org2clo[target]
            
            