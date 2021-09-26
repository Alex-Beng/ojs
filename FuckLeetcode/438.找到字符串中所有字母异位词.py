#
# @lc app=leetcode.cn id=438 lang=python3
#
# [438] 找到字符串中所有字母异位词
#

# @lc code=start
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        def s2vec(s):
            vec = [0]*26
            for c in s:
                vec[ord(c)-ord('a')] += 1
            return tuple(vec)
        pvec = s2vec(p)
        
        n = len(s)
        b = 0
        e = len(p)-1
        if e>n:
            return []
        tvec = list(s2vec(s[b:e+1]))

        ans = []
        while e<n:
            if tuple(tvec) == pvec:
                ans.append(b)
            tvec[ord(s[b])-ord('a')] -= 1
            if e+1 == n:
                break
            tvec[ord(s[e+1])-ord('a')] += 1
            b += 1
            e += 1
        return ans
# @lc code=end

