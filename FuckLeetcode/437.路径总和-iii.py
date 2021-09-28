#
# @lc app=leetcode.cn id=437 lang=python3
#
# [437] 路径总和 III
#

from util import TreeNode

# @lc code=start
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        ans = 0
        def dfs(node: TreeNode, sums: [int]):
            nonlocal ans
            if node is None:
                return
            for i,s in enumerate(sums):
                if node.val+s == targetSum:
                    ans += 1
                sums[i] += node.val
            sums.append(0)
            dfs(node.left, sums)
            dfs(node.right, sums)

            for i,s in enumerate(sums):
                sums[i] -= node.val
            del sums[-1]
        dfs(root, [0])
        return ans
            
# @lc code=end

