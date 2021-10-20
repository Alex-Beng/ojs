#
# @lc app=leetcode.cn id=637 lang=python3
#
# [637] 二叉树的层平均值
#

from util import TreeNode

# @lc code=start
class Solution:
    def averageOfLevels(self, root: TreeNode) -> [float]:
        ans = []
        def lord(nodes: [TreeNode]):
            nodes = [nd for nd in nodes if nd is not None]
            n = len(nodes)
            if not n:
                return
            ts = 0
            new_nodes = []
            for nd in nodes:
                ts += nd.val
                new_nodes.append(nd.left)
                new_nodes.append(nd.right)
            ans.append(ts/n)
            if len(new_nodes):
                lord(new_nodes)
        lord([root])
        return ans

# @lc code=enduu,l,m

