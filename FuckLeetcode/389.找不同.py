#
# @lc app=leetcode.cn id=389 lang=python3
#
# [389] 找不同
#

# @lc code=start
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        def s2vec(s: str):
            vec = [0]*26
            for c in s:
                vec[ord(c)-ord('a')] += 1
            return tuple(vec)
        svec = s2vec(s)
        tvec = s2vec(t)
        for i in range(26):
            if svec[i] != tvec[i]:
                return chr(i+ord('a'))
        
# @lc code=end

