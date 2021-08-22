# Definition for a binary tree node.
from util import TreeNode
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:

        def check(nodes):
            sons = []
            for nd in nodes:
                if nd is not None:
                    sons.append(nd.left)
                    sons.append(nd.right)
            n = len(sons)
            if n==0:
                return True
            for i in range(n//2):
                j = n-i-1
                if sons[i] is not None and sons[j] is not None \
                    and sons[i].val == sons[j].val \
                        or \
                    sons[i] is None and sons[j] is None:
                    pass
                else:
                    return False
            return check(sons)
        
        return check([root])