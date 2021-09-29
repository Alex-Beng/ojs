#
# @lc app=leetcode.cn id=2011 lang=python3
#
# [2011] 执行操作后的变量值
#

# @lc code=start
class Solution:
    def finalValueAfterOperations(self, operations: [str]) -> int:
        return sum([44-ord(i[1]) for i in operations])
# @lc code=end

