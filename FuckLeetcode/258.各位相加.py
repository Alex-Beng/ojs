#
# @lc app=leetcode.cn id=258 lang=python3
#
# [258] 各位相加
#

# @lc code=start
class Solution:
    def addDigits(self, num: int) -> int:
        if num>9:
            return 9 if num%9==0 else num%9
        else:
            return num
# @lc code=end

