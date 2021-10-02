#
# @lc app=leetcode.cn id=492 lang=python3
#
# [492] 构造矩形
#

# @lc code=start
from math import sqrt
class Solution:
    def constructRectangle(self, area: int) -> [int]:
        w = int(sqrt(area)+0.5)
        while w >= 1:
            if area%w == 0:
                return [area//w, w]
            w -= 1
# @lc code=end

