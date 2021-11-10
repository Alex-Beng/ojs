#
# @lc app=leetcode.cn id=830 lang=python3
#
# [830] 较大分组的位置
#

# @lc code=start
import re
class Solution:
    def largeGroupPositions(self, s: str) -> List[List[int]]:
        return [[rg.span()[0], rg.span()[1]-1] for rg in re.finditer(r"(.)\1{2,}", s)]
# @lc code=end