from util import *
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        def searchBST(node: TreeNode, val, tnode):
            if node is None:
                return False
            if node.val == val:
                if node != tnode:
                    return True
                else:
                    return False
            elif node.val < val:
                return searchBST(node.right, val, tnode) 
            else:
                return searchBST(node.left, val, tnode)
        values = []
        def getValues(node: TreeNode):
            if node is None:
                return
            values.append(node)
            getValues(node.left)
            getValues(node.right)
        getValues(root)

        for v in values:
            another = k-v.val
            if searchBST(root, another, v):
                return True
        return False
            
