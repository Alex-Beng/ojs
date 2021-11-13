#
# @lc app=leetcode.cn id=1812 lang=python3
#
# [1812] 判断国际象棋棋盘中一个格子的颜色
#

# @lc code=start
class Solution:
    def squareIsWhite(self, coordinates: str) -> bool:
        f = ord(coordinates[0])-ord('a')
        s = ord(coordinates[1])-ord('1')
        return (f+s)&1 > 0
# @lc code=end