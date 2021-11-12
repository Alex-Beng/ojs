#
# @lc app=leetcode.cn id=1446 lang=python3
#
# [1446] 连续字符
#

# @lc code=start
import re
class Solution:
    def maxPower(self, s: str) -> int:
        return max([i.span()[1]-i.span()[0] for i in re.finditer(r"(.)\1{0,}", s)])
# @lc code=end