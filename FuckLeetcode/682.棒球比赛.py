#
# @lc app=leetcode.cn id=682 lang=python3
#
# [682] 棒球比赛
#

# @lc code=start
class Solution:
    def calPoints(self, ops: [str]) -> int:
        scores = []
        for op in ops:
            if op=='C':
                del scores[-1]
            elif op=='D':
                scores.append(scores[-1]*2)
            elif op=='+':
                scores.append(scores[-1]+scores[-2])
            else:
                scores.append(int(op))
        return sum(scores)
# @lc code=end

