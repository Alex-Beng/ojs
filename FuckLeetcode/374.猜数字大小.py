#
# @lc app=leetcode.cn id=374 lang=python3
#
# [374] 猜数字大小
#

# @lc code=start
from random import random
def guess(num: int) -> int:
        return random()>0.5
class Solution:
    def guessNumber(self, n: int) -> int:
        L = 1
        R = n
        while L<R:
            print(L, R)
            m = (L+R)//2
            r = guess(m)
            if r==-1:
                R = m-1
            elif r==1:
                L = m+1
            else:
                return m
        return L
# @lc code=end
