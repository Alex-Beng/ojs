#
# @lc app=leetcode.cn id=107 lang=python3
#
# [107] 二叉树的层序遍历 II
#

# @lc code=start

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> [[int]]:
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
            ans.insert(0, layer)
            if len(next_layer):
                layer_view(next_layer)
        if not root:
            return []
        layer_view([root])
        return ans
# @lc code=end