#
# @lc app=leetcode.cn id=44 lang=python3
#
# [44] 通配符匹配
#

# @lc code=start
from functools import lru_cache
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        sn = len(s)
        pn = len(p)
        if sn==0:
            return set(p)=={'*'} or pn==0
        if pn==0:
            return sn==0

        dp = [[0]*(sn+1) for _ in range(pn+1)]

        dp[0][0] = 1
        for j in range(1, pn+1):
            if set(p[:j]) == {'*'}:
                dp[j][0] = 1
        for j in range(1, pn+1):
            for i in range(1, sn+1):
                if p[j-1]=='*':
                    if sum(dp[j-1][:i+1])>0:
                        dp[j][i] = 1
                else:
                    if s[i-1]==p[j-1] or p[j-1] == '?':
                        dp[j][i] = dp[j-1][i-1]
                    else:
                        dp[j][i] = 0
        return dp[pn][sn]==1
                
# @lc code=end

s = Solution()
s.isMatch(
    # "adceb", "a*b"
    # "adceb", "*a*b"
    # "mississippi", "m??*ss*?i*pi"
    # "abcabczzzde","*abc???de*"
    # "ho", "**ho"
    "aaaaaabbaabaaaaabababbabbaababbaabaababaaaaabaaaabaaaabababbbabbbbaabbababbbbababbaaababbbabbbaaaaaaabbaabbbbababbabbaaabababaaaabaaabaaabbbbbabaaabbbaabbbbbbbaabaaababaaaababbbbbaabaaabbabaabbaabbaaaaba",
    "*bbb**a*******abb*b**a**bbbbaab*b*aaba*a*b**a*abb*aa****b*bb**abbbb*b**bbbabaa*b**ba**a**ba**b*a*a**aaa"

)