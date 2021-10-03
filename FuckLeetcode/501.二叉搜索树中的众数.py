#
# @lc app=leetcode.cn id=501 lang=python3
#
# [501] 二叉搜索树中的众数
#
from util import TreeNode
# @lc code=start
class Solution:
    def findMode(self, root: TreeNode) -> [int]:
        num2times = dict()
        def dfs(node: TreeNode):
            nonlocal num2times
            if node is None:
                return
            if node.val in num2times:
                num2times[node.val] += 1
            else:
                num2times[node.val] = 1
            dfs(node.left)
            dfs(node.right)
        
        dfs(root)
        maxt = max(num2times.values())
        ans = []
        for n in num2times:
            if num2times[n] == maxt:
                ans.append(n)
        return ans
# @lc code=end

