#
# @lc app=leetcode.cn id=375 lang=python3
#
# [375] 猜数字大小 II
#

# @lc code=start
from functools import lru_cache
class Solution:
    def getMoneyAmount(self, n: int) -> int:
        @lru_cache(None)
        def dp(i: int, j: int) -> int:
            if j<i:
                return float('inf')
            if j-i==0:
                return 0
            elif j-i==1:
                return i
            elif j-i==2:
                return i+1
            m = (i+j)//2
            tans = float('inf')
            for tm in range(m, j):
                # set tm pivot, cost:
                t_cost = max(dp(i, tm-1),dp(tm+1,j))+tm
                tans = min(tans, t_cost)
            return tans
        return dp(1, n)
# @lc code=end