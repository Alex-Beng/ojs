#
# @lc app=leetcode.cn id=299 lang=python3
#
# [299] 猜数字游戏
#

# @lc code=start
class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        def s2vec(s: str):
            vec = [0]*10
            for c in s:
                n = ord(c)-ord('0')
                vec[n] += 1
            return vec
        s_vec = [0]*10
        g_vec = [0]*10
        bulls = 0
        cows = 0
        for i,c in enumerate(guess):
            sc = secret[i]
            gc = guess[i]
            if sc == gc:
                bulls += 1
            else:
                s_vec[ord(sc)-ord('0')] += 1
                g_vec[ord(gc)-ord('0')] += 1
        for i in range(10):
            cows += min(g_vec[i], s_vec[i])
        return f'{bulls}A{cows}B'
# @lc code=end