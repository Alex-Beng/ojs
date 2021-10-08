from util import TreeNode

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        ans = 0
        def depth(node: TreeNode):
            nonlocal ans
            if node is None:
                return 0
            l = depth(node.left)
            r = depth(node.right)
            ans = max(ans, l+r)
            return max(l,r)+1
        depth(root)
        return ans
        