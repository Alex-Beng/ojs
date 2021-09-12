#
# @lc app=leetcode.cn id=678 lang=python3
#

from functools import lru_cache
class Solution:
    def checkValidString(self, s: str) -> bool:
        n = len(s)
        @lru_cache(None)
        def dfs(depth, cnt):
            if cnt < 0:
                return False

            if depth == n:
                return cnt == 0
            cha = s[depth]
            if cha == '(':
                return dfs(depth+1, cnt+1)
            elif cha == ')':
                if cnt > 0:
                    return dfs(depth+1, cnt-1)
                else:
                    return False
            else:
                return dfs(depth+1, cnt-1) or dfs(depth+1, cnt) or dfs(depth+1, cnt+1)
        return dfs(0,0)
s = Solution()
res = s.checkValidString(
    # "()"
    # "(*)"
    #  "(*))("
    "(((((*(()((((*((**(((()()*)()()()*((((**)())*)*)))))))(())(()))())((*()()(((()((()*(())*(()**)()(())"
)
print(res)
