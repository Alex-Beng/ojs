#
# @lc app=leetcode.cn id=38 lang=python3
#
# [38] 外观数列
#

# @lc code=start
from functools import lru_cache
class Solution:
    def countAndSay(self, n: int) -> str:
        ans = '1'
        def trans(s: str) -> str:
            n = len(s)
            i = 0
            ans = ''
            while i<n:
                j = i
                while j<n and s[j] == s[i]:
                    j += 1
                ans += f'{j-i}{s[i]}'
                i = j
            return ans
        for _ in range(1, n):
            ans = trans(ans)
        return ans
            

# @lc code=end
