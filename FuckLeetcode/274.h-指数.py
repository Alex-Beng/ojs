#
# @lc app=leetcode.cn id=274 lang=python3
#
# [274] H 指数
#

# @lc code=start
class Solution:
    def hIndex(self, citations: [int]) -> int:
        cites = citations
        cites.sort()

        n = len(cites)
        L = 0
        R = n-1
        while L<=R:
            m = (L+R)//2
            th = n-m
            cm = cites[m]
            if th <= cm:
                R = m-1
            else:
                L = m+1
        return n-L
# @lc code=end

