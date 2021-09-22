#
# @lc app=leetcode.cn id=342 lang=python3
#
# [342] 4的幂
#

# @lc code=start
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        shifts = list(range(2,31,2))
        # print(shifts)
        if n<=0:
            return False
        elif n==1:
            return True
        for s in shifts:
            if n>>s == 1 and n>>s<<s == n:
                return True
        return False
        # return n>0 and 1073741824%n==0
# @lc code=end

