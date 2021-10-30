#
# @lc app=leetcode.cn id=319 lang=python3
#
# [319] 灯泡开关
#

# @lc code=start
from math import sqrt
class Solution:
    def bulbSwitch(self, n: int) -> int:
        '''
        O(1)?
        '''
        return int(sqrt(n))
        '''
        O(logn)
        '''
        sq_table = [i*i for i in range(1, 31624)]

        L = 0
        R = len(sq_table)-1
        while L<=R:
            m = (L+R)//2
            sm = sq_table[m]
            if sm <= n:
                L = m+1
            else:
                R = m-1
        return R+1
# @lc code=end