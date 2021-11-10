#
# @lc app=leetcode.cn id=917 lang=python3
#
# [917] 仅仅反转字母
#

# @lc code=start
class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        def get_next_cha(s: str) -> str:
            for c in s[::-1]:
                if ord('a') <= ord(c) <= ord('z') or \
                    ord('A') <= ord(c) <= ord('Z'):
                    yield c
        
        cha_iter = get_next_cha(s)
        s = list(s)
        for i,c in enumerate(s):
            if ord('a') <= ord(c) <= ord('z') or \
                    ord('A') <= ord(c) <= ord('Z'):
                s[i] = next(cha_iter)
        return ''.join(s)
# @lc code=end

