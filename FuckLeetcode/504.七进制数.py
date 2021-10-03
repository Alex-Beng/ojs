#
# @lc app=leetcode.cn id=504 lang=python3
#
# [504] 七进制数
#

# @lc code=start
class Solution:
    def convertToBase7(self, num: int) -> str:
        if num==0:
            return "0"
        sign = ""
        if num<0:
            sign = "-"
            num = -num
        ans = ""
        def to7(num: int):
            nonlocal ans
            if num == 0:
                return
            t = num%7
            ans = str(t)+ans
            to7(num//7)
        to7(num)
        return f'{sign}{ans}'
# @lc code=end
s = Solution()
r = s.convertToBase7(
    7
)
print(r)