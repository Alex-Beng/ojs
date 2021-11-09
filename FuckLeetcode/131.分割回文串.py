#
# @lc app=leetcode.cn id=131 lang=python3
#
# [131] 分割回文串
#

# @lc code=start
from functools import lru_cache
class Solution:
    def partition(self, s: str) -> [[str]]:
        @lru_cache(None)
        def is_re(s: str) -> bool:
            n = len(s)
            if n==0 or n==1:
                return True
            if s[0] == s[-1]:
                return is_re(s[1:-1])
            else:
                return False
        n = len(s)
        ans = []
        curr = []
        def dfs(layer: int):
            if layer == n:
                ans.append(tuple(curr))
                return
            for j in range(layer+1, n+1):
                if is_re(s[layer:j]):
                    curr.append(s[layer:j])
                    dfs(j)
                    del curr[-1]
        dfs(0)
        return [list(i) for i in ans]
# @lc code=end