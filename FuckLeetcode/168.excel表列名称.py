#
# @lc app=leetcode.cn id=168 lang=python3
#
# [168] Excel表列名称
#

# @lc code=start
from functools import lru_cache
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        @lru_cache(None)
        def n2c(n):
            return chr(n-1+ord('A'))
        ans = []
        while columnNumber != 0:
            d = columnNumber%26
            if d==0:
                d = 26
            
            ans.insert(0, n2c(d))
            columnNumber -= d
            columnNumber //= 26
            print(ans, columnNumber, d)
        return ''.join(ans)
            
# @lc code=end

s = Solution()
rs = s.convertToTitle(
    # 701
    52
    # 1
)
print(rs)