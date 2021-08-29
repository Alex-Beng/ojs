from util import *
from functools import lru_cache
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        @lru_cache(None)
        def dfs(node: TreeNode, curr_sum):
            if node is None:
                return False
            if node.left is None and node.right is None:
                if curr_sum+node.val == targetSum:
                    return True
                else:
                    return False
            else:
                return dfs(node.left, curr_sum+node.val) or dfs(node.right, curr_sum+node.val)
        return dfs(root, 0)