from util import *
from copy import deepcopy
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> [[int]]:
        ans = []

        def dfs(node: TreeNode, curr_sum, curr_path):
            if node is None:
                return
            if node.left is None and node.right is None:
                if curr_sum+node.val == targetSum:
                    ans.append(tuple(curr_path+[node.val]))
                    return
                else:
                    return
            else:
                dfs(node.left, curr_sum+node.val, curr_path+[node.val])
                dfs(node.right, curr_sum+node.val, curr_path+[node.val])
        dfs(root, 0, [])
        
        print(ans)
        return [list(i) for i in ans]
