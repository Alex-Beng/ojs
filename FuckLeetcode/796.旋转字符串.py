#
# @lc app=leetcode.cn id=796 lang=python3
#
# [796] 旋转字符串
#

# @lc code=start
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        table = set()
        n = len(s)
        for i in range(n):
            table.add(s[i+1:]+s[:i+1])
        return goal in table
# @lc code=end