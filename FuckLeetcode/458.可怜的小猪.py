#
# @lc app=leetcode.cn id=458 lang=python3
#
# [458] 可怜的小猪
#

# @lc code=start
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        T = minutesToTest//minutesToDie
        for x in range(1, buckets+1):
            if (T+1)**x >= buckets:
                return x
# @lc code=end