#
# @lc app=leetcode.cn id=606 lang=python3
#
# [606] 根据二叉树创建字符串
#
from util import TreeNode

# @lc code=start

class Solution:
    def tree2str(self, root: TreeNode) -> str:
        def pord_str(node: TreeNode) -> str:
            if node is None:
                return ''
            t_ans = f'{node.val}'
            if node.left is None and node.right is None:
                return t_ans
            if node.left is None:
                t_ans += f'()({pord_str(node.right)})'
            else:
                t_ans += f'({pord_str(node.left)})'
                if node.right is not None:
                    t_ans += f'({pord_str(node.right)})'
            return t_ans
        return pord_str(root)
# @lc code=end
