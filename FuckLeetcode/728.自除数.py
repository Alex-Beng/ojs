#
# @lc app=leetcode.cn id=728 lang=python3
#
# [728] 自除数
#

# @lc code=start
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> [int]:
        def valid(n):
            np = n
            while n!=0:
                t = n%10
                if t==0 or np%t != 0:
                    return False
                n//=10
            return True
        return [n for n in range(left, right+1) if valid(n)]
# @lc code=end