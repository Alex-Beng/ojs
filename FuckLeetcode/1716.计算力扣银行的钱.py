#
# @lc app=leetcode.cn id=1716 lang=python3
#
# [1716] 计算力扣银行的钱
#

# @lc code=start
class Solution:
    def totalMoney(self, n: int) -> int:
        return sum([(i*2+6)*7//2 for i in range(1,n//7+1)]) + sum([n//7+1+i for i in range(n%7)])
# @lc code=end