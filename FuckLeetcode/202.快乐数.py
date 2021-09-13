#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#

# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        been = set()
        def happy(n):
            if n in been:
                return False
            else:
                been.add(n)
            nn = 0
            while n != 0:
                ld = n%10
                n //= 10
                nn += ld*ld
            if nn == 1:
                return True
            else:
                return happy(nn)
        return happy(n)
# @lc code=end

