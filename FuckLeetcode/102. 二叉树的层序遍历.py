from util import *
class Solution:
    def levelOrder(self, root: TreeNode) -> [[int]]:
        ans = []
        def layer_view(nodes):
            layer = []
            next_layer = []
            for node in nodes:
                layer.append(node.val)
                if node.left is not None:
                    next_layer.append(node.left)
                if node.right is not None:
                    next_layer.append(node.right)
            ans.append(layer)
            if len(next_layer):
                layer_view(next_layer)
        if not root:
            return []
        layer_view([root])
        return ans
