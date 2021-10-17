#
# @lc app=leetcode.cn id=1009 lang=python3
#
# [1009] 十进制整数的反码
#

# @lc code=start
class Solution:
    def bitwiseComplement(self, n: int) -> int:
        if not n:
            return 1
        L = 0
        R = 32
        ans = 32
        while L<=R:
            m = (L+R)//2
            twom = (1<<m)
            if n<twom:
                R = m-1
                ans = m
            else:
                L = m+1
        twon = (1<<ans)
        return twon - n - 1

# @lc code=end

