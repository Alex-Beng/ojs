class Solution:
    def maxDepth(self, root: 'Node') -> int:
        def depth(node: 'Node') -> int:
            if node is None:
                return 0
            ans = 0
            for c in node.children:
                ans = max(ans, depth(c))
            return ans + 1
        return depth(root)
                