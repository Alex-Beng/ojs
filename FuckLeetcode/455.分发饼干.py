#
# @lc app=leetcode.cn id=455 lang=python3
#
# [455] 分发饼干
#

# @lc code=start
class Solution:
    def findContentChildren(self, g: [int], s: [int]) -> int:
        g.sort()
        s.sort()
        j = 0
        ans = 0
        for i,tg in enumerate(g):
            while j<len(s) and s[j]<tg:
                j += 1
            if j==len(s):
                return ans
            ans += 1
            j += 1
        return ans

# @lc code=end

