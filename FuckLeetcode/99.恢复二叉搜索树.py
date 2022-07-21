from util import TreeNode

from functools import lru_cache
class Solution:
    def recoverTree(self, root) -> None:
        mid_order = []

        def mid_o(node: TreeNode):
            if node is None:
                return
            mid_o(node.left)
            mid_order.append(node)
            mid_o(node.right)
        mid_o(root)

        sorted_o = sorted(mid_order, key=lambda k: k.val)
        sorted_o = [i.val for i in sorted_o]

        for i, n in enumerate(mid_order):
            if n.val != sorted_o[i]:
                n.val = sorted_o[i]
        return root
        
        
        @lru_cache(None)
        def min_t(node: TreeNode):
            if node is None:
                return None
            lm = min_t(node.left)
            rm = min_t(node.right)
            t_nodes = [lm, rm, node]
            t_nodes = [n for n in t_nodes if n is not None]
            
            return min(t_nodes, key=lambda k: k.val)
        @lru_cache(None)
        def max_t(node: TreeNode):
            if node is None:
                return None
            lm = max_t(node.left)
            rm = max_t(node.right)
            t_nodes = [lm, rm, node]
            t_nodes = [n for n in t_nodes if n is not None]
            
            return max(t_nodes, key=lambda k: k.val)
        
        def dfs(node: TreeNode):
            # dfs 检查异常结点
            if node is None:
                return
            mid = node.val
            if min_t(node.right) is not None and mid > min_t(node.right).val:
                t = mid
                node.val = min_t(node.right).val
                min_t(node.right).val = t
            elif max_t(node.left) is not None and mid < max_t(node.left).val:
                t = mid
                node.val = max_t(node.left).val
                max_t(node.left).val = t
            dfs(node.left)
            dfs(node.right)
        dfs(root)