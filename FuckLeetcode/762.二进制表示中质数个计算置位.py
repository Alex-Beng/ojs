#
# @lc app=leetcode.cn id=762 lang=python3
#
# [762] 二进制表示中质数个计算置位
#

# @lc code=start
class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        primes = {2,3,5,7,11,13,17,19,23,29,31}
        def get_bits(n):
            cnt = 0
            while n!=0:
                n &= (n-1)
                cnt += 1
            return cnt
        return len([n for n in range(left, right+1) if get_bits(n) in primes])
# @lc code=end