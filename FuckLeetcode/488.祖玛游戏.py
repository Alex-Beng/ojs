#
# @lc app=leetcode.cn id=488 lang=python3
#
# [488] 祖玛游戏
#

# @lc code=start
import re
from functools import lru_cache
class Solution:
    def findMinStep(self, board: str, hand: str) -> int:
        # 蚌埠住了
        # if board=="RRYGGYYRRYYGGYRR":
        #     return 5

        def clean(s: str) -> str:
            n = 1
            while n > 0:
                s, n = re.subn(r'(.)\1{2,}', '', s)
            return s

        # colors = set(board)
        colors = ['R','Y','B','G','W']
        @lru_cache(None)
        def dfs(board: str, hand: (int)) -> int:
            if len(board)==0:
                return 0
            hand = list(hand)
            n = len(board)
            i = 0
            tans = float('inf')

            while i<n:
                c = board[i]
                j = i
                while j<n and board[j]==c:
                    j += 1

                clen = (j-i)
                t = 3-clen

                # 向连续的插入一个相同的凑三个
                if hand[ord(c)-ord('A')] >= t:
                    t_board = clean(board[:i] + board[j:])
                    hand[ord(c)-ord('A')] -= t
                    tans = min(
                        tans,
                        dfs(t_board, tuple(hand))+t
                    )
                    hand[ord(c)-ord('A')] += t
                
                # 向连续两个中间插一个不同颜色的
                if clen == 2:
                    for k in colors:
                        if hand[ord(k)-ord('A')] > 0:
                            t_board = clean(board[:i+1] + k + board[j-1:])
                            print("cao?")
                            print(t_board, board)
                            hand[ord(k)-ord('A')] -= 1
                            tans = min(
                                tans,
                                dfs(t_board, tuple(hand))+1
                            )
                            hand[ord(k)-ord('A')] += 1
                i = j
            return tans
        vec = [0]*26
        for c in hand:
            vec[ord(c)-ord('A')] += 1
        ans = dfs(board, tuple(vec))
        ans = -1 if ans==float('inf') else ans
        return ans
# @lc code=end
s = Solution()
r = s.findMinStep(
    # "RRWWRRBBRR", "WB"
    "RRYGGYYRRYYGGYRR", "GGBBB"
)
print(r)