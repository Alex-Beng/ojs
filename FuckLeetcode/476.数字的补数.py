#
# @lc app=leetcode.cn id=476 lang=python3
#
# [476] 数字的补数
#

# @lc code=start
class Solution:
    def findComplement(self, num: int) -> int:
        L = 0
        R = 32
        ans = 32
        while L<=R:
            m = (L+R)//2
            twom = (1<<m)
            if num<twom:
                R = m-1
                ans = m
            else:
                L = m+1
        twon = (1<<ans)
        return twon - num - 1
# @lc code=end
s = Solution()
r = s.findComplement(
    2
)
print(r)