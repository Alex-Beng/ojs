#
# @lc app=leetcode.cn id=367 lang=python3
#
# [367] 有效的完全平方数
#

# @lc code=start
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        L = 1
        R = num
        while L<=R:
            m = (L+R)//2
            t = m*m
            if t > num:
                R = m-1
            elif t < num:
                L = m+1
            else:
                return True
        return False
# @lc code=end

