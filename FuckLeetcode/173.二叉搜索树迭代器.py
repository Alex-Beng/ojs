#
# @lc app=leetcode.cn id=173 lang=python3
#
# [173] 二叉搜索树迭代器
#
from util import TreeNode
# @lc code=start

class BSTIterator:

    def __init__(self, root: TreeNode):
        ans = []
        def ms(node: TreeNode):
            if node is None:
                return
            ms(node.left)
            ans.append(node.val)
            ms(node.right)
        ms(root)
        self.ans = ans
        self.i = 0

    def next(self) -> int:
        t = self.ans[self.i]
        self.i += 1
        return t


    def hasNext(self) -> bool:
        return self.i < len(self.ans)


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
# @lc code=end

