#
# @lc app=leetcode.cn id=8 lang=python3
#
# [8] 字符串转换整数 (atoi)
#

# @lc code=start
from functools import lru_cache
class Solution:
    def myAtoi(self, s: str) -> int:
        @lru_cache(10)
        def is_num(c: str):
            if ord('0')<=ord(c)<=ord('9'):
                return True, ord(c)-ord('0')
            else:
                return False,0
        s = s.strip(' ')

        n = len(s)
        if n==0:
            return 0
        i = 0
        sign = 1
        if s[0]=='-':
            i += 1
            sign = -1
        elif s[0]=='+':
            i += 1
        ans = 0
        while i<n:
            c = s[i]
            valid, tn = is_num(c)
            if not valid:
                break
            ans += tn
            ans *= 10
            i += 1
            print(ans)
        ans //= 10
        ans *= sign
        
        ans = min(ans, 2**31-1)
        ans = max(ans, -2**31)
        return ans
# @lc code=end
s = Solution()
s.myAtoi(
"-91283472332"
)