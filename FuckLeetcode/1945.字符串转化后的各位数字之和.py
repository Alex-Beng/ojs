#
# @lc app=leetcode.cn id=1945 lang=python3
#
# [1945] 字符串转化后的各位数字之和
#

# @lc code=start
from functools import lru_cache
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        @lru_cache(None)
        def c2n(c):
            t = ord(c)-ord('a')+1
            return t

        num = 0
        for n in [c2n(c) for c in s]:
            num += n if n<10 else n//10+n%10

        for _ in range(k-1):
            new_num = 0
            while num != 0:
                new_num += num%10
                num //= 10
            num = new_num
        return num
        
# @lc code=end
