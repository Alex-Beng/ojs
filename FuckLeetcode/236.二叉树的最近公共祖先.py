#
# @lc app=leetcode.cn id=236 lang=python3
#
# [236] 二叉树的最近公共祖先
#

from util import TreeNode

# @lc code=start

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        midOrder = []
        def ms(node: TreeNode):
            if node is None:
                return
            ms(node.left)
            midOrder.append(node)
            ms(node.right)
        ms(root)
        node2idx = dict()
        for i,n in enumerate(midOrder):
            node2idx[n] = i
        def search(t: TreeNode):
            if node2idx[t]<node2idx[p] and node2idx[t]<node2idx[q]:
                return search(t.right)
            elif node2idx[t]>node2idx[p] and node2idx[t]>node2idx[q]:
                return search(t.left)
            else:
                return t
        return search(root)
        
# @lc code=end

