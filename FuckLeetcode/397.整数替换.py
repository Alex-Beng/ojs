#
# @lc app=leetcode.cn id=397 lang=python3
#
# [397] 整数替换
#

# @lc code=start
from functools import lru_cache
class Solution:
    def integerReplacement(self, n: int) -> int:
        @lru_cache(None)
        def times(n: int) -> int:
            if n==1:
                return 0
            if n&1:
                return min(times(n-1)+1, times(n+1)+1)
            else:
                return times(n//2)+1
        return times(n)
# @lc code=end

