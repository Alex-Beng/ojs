#
# @lc app=leetcode.cn id=671 lang=python3
#
# [671] 二叉树中第二小的节点
#
from util import TreeNode
# @lc code=start

class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        def find_sec(node: TreeNode):
            if node is None:
                return float('inf')
            if node.left is None:
                return float('inf')
        
            l_ans = find_sec(node.left) if node.left.val==node.val else node.left.val
            r_ans = find_sec(node.right) if node.right.val==node.val else node.right.val
            return min(l_ans, r_ans)
        ans = find_sec(root) 
        ans = -1 if ans==float('inf') else ans
        return ans
# @lc code=end

