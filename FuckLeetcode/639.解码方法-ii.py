#
# @lc app=leetcode.cn id=639 lang=python3
#
# [639] 解码方法 II
#

# @lc code=start
from functools import lru_cache
class Solution:
    def numDecodings(self, s: str) -> int:
        sig = set([str(i) for i in range(1, 27)])
        fir2num = {
            '0':0,
            '1':9,
            '2':6,
            '3':0,
            '4':0,
            '5':0,
            '6':0,
            '7':0,
            '8':0,
            '9':0,
        }
        sec2num = {
            '0':2,
            '1':2,
            '2':2,
            '3':2,
            '4':2,
            '5':2,
            '6':2,
            '7':1,
            '8':1,
            '9':1,
        }

        n = len(s)
        dp = [0]*n

        @lru_cache(None)
        def s2candi(s):
            if s in sig:
                return 1
            # *
            # x* *x **
            if len(s) == 1:
                return 9 if s!='0'  else 0
            elif s == '**':
                return 15
            elif s[0] == '*':
                return sec2num[s[1]]
            elif s[1] == '*':
                return fir2num[s[0]]
            else:
                return 0
        dp[0] = s2candi(s[0])
        if n==1:
            return dp[0]
        # print(dp[0]*s2candi(s[1]), s2candi(s[0:2]))
        dp[1] = dp[0]*s2candi(s[1]) + s2candi(s[0:2])
        for i in range(2, n):
            dp[i] += dp[i-1]*s2candi(s[i]) + dp[i-2]*s2candi(s[i-1:i+1])
            dp[i] %= 1000000007
        # print(dp)
        return dp[-1]
# @lc code=end
