from util import TreeNode, make_tree, print_tree

from functools import lru_cache
class Solution:
    def evaluateTree(self, root: TreeNode) -> bool:
        @lru_cache(1007)
        def comp_val(root: TreeNode) -> bool:
            '''
            if root.val == 0 or root.val == 1:
                return bool(root.val)
            '''
            # a better implement be like
            if root.left is None:
                return root.val == 1
            elif root.val == 2:
                return comp_val(root.left) | comp_val(root.right)
            elif root.val == 3:
                return comp_val(root.left) & comp_val(root.right)
        return comp_val(root)

root = make_tree('[2,1,3,null,null,0,1]')
print_tree(root)

s = Solution()
res = s.evaluateTree(root)
print(res)
