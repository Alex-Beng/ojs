from functools import lru_cache
class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        MOD = int(1e9+7)
        @lru_cache(None)
        def dfs(c, n):
            if n == 0:
                return 1
            if n < 26:
                return 2 if c + n >= 26 else 1
            
            if c + 1 == 26:
                return (dfs(c, n-26) + dfs((c+1)%26, n-26) + dfs((c+2)%26, n-26) ) % MOD
            else:
                return (dfs(c, n-26) + dfs((c+1)%26, n-26)) % MOD
        res = 0
        for c in s:
            cn = ord(c) - ord('a')
            res += dfs(cn, t)
            # print(c, cn, res, dfs(cn, t))
        return res % MOD

INPUT = [
    ("abcyy", 2),
    ("azbk", 1),
    ("jqktcurgdvlibczdsvnsg", 7517)
]