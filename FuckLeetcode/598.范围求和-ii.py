#
# @lc app=leetcode.cn id=598 lang=python3
#
# [598] 范围求和 II
#

# @lc code=start
class Solution:
    def maxCount(self, m: int, n: int, ops: [[int]]) -> int:
        if not len(ops):
            return m*n
        ac,ar = ops[0]
        for c,r in ops[1:]:
            ac = min(ac, c)
            ar = min(ar, r)

        return ac*ar
# @lc code=end

