#
# @lc app=leetcode.cn id=521 lang=python3
#
# [521] 最长特殊序列 Ⅰ
#

# @lc code=start
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        na = len(a)
        nb = len(b)
        if na!=nb:
            return max(na, nb)
        else:
            if a!=b:
                return na
            else:
                return -1

# @lc code=end

s = Solution()
s.findLUSlength(
    "aefawfawfawfaw", "aefawfeawfwafwaef"
)