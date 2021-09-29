#
# @lc app=leetcode.cn id=223 lang=python3
#
# [223] 矩形面积
#

# @lc code=start
class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        def cov():
            if bx1>=ax2 or bx2<=ax1 or by1>=ay2 or by2<=ay1:
                return 0
            
            l = max(ax1, bx1)
            r = min(ax2, bx2)
            u = min(by2, ay2)
            d = max(ay1, by1)
            return abs(l-r)*abs(u-d)
        return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - cov()
# @lc code=end

