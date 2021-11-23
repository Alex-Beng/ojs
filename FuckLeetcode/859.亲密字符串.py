#
# @lc app=leetcode.cn id=859 lang=python3
#
# [859] 亲密字符串
#

# @lc code=start
class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        def s2vec(s: str):
            vec = [0]*26
            for c in s:
                vec[ord(c)-ord('a')] += 1
            return tuple(vec)
        s_vec = s2vec(s)
        g_vec = s2vec(goal)
        # print(s_vec, g_vec)
        if s_vec != g_vec:
            return False
        err_pair = 0
        for i in range(len(s)):
            if s[i] != goal[i]:
                err_pair += 1
        return err_pair==2 or err_pair==0 and max(s_vec)>1
# @lc code=end