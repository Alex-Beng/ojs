#
# @lc app=leetcode.cn id=205 lang=python3
#
# [205] 同构字符串
#

# @lc code=start
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        n = len(s)
        s2t = dict()
        t2s = dict()
        for i in range(n):
            sc = s[i]
            tc = t[i]
            # print(sc, tc, s2t)
            if sc in s2t:
                if tc != s2t[sc]:
                    return False
            elif tc in t2s:
                if sc != t2s[tc]:
                    return False
            else:
                s2t[sc] = tc
                t2s[tc] = sc
            
        return True
    
# @lc code=end

s = Solution()
r = s.isIsomorphic(
    # "foo","bar"
    # "paper","title"
    "badc", "baba"
)
print(r)