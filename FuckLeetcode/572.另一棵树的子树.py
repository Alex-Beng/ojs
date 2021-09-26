#
# @lc app=leetcode.cn id=572 lang=python3
#
# [572] 另一棵树的子树
#
from util import TreeNode
# @lc code=start
from functools import lru_cache
class Solution:
    def isSubtree(self, root: TreeNode, subRoot: TreeNode) -> bool:
        @lru_cache(None)
        def check(t1: TreeNode, t2: TreeNode):
            if t1 is None and t2 is None:
                return True
            elif t1 is not None and t2 is not None:
                if t1.val == t2.val:
                    return check(t1.left, t2.left) and check(t1.right, t2.right)
                else:
                    return False
            else:
                return False
        ans = False
        def dfs(node: TreeNode):
            nonlocal ans

            if node is None or ans:
                return 

            if node.val == subRoot.val:
                ans |= check(node, subRoot)
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        return ans
            
# @lc code=end

