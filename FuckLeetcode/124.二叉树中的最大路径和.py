#
# @lc app=leetcode.cn id=124 lang=python3
#
# [124] 二叉树中的最大路径和
#

from util import TreeNode

# @lc code=start

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        ans = float('-inf')

        # 经过node的最大路径
        def maxPath(node: TreeNode) -> int:
            nonlocal ans
            if node is None:
                return float('-inf')
            lsum = maxPath(node.left)
            rsum = maxPath(node.right)
            # print(lsum, rsum)

            ans = max(ans, node.val, node.val+max(lsum, rsum), node.val+lsum+rsum)
            # print(ans)
            return max(node.val, node.val+max(lsum, rsum))
        t = maxPath(root)
        ans = max(ans, t)
        # ans = max(ans, maxPath(root))
        # print(ans)
        return ans

# @lc code=end

