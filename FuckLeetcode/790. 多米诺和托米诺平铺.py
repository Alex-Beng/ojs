from functools import lru_cache
class Solution:
    def numTilings(self, n: int) -> int:
        MOD = int(1e9+7)
        dpF = [0]*(n+7)
        dpE = [0]*(n+7)
        dpF[1] = 1
        dpF[2] = 2
        dpE[1] = 0
        dpE[2] = 2
        for i in range(3, n+1):
            dpF[i] = dpF[i-1] + dpF[i-2] + dpE[i-1]
            dpE[i] = dpF[i-2] + dpF[i-2] + dpE[i-1]
            dpF[i] %= MOD
            dpE[i] %= MOD
        return dpF[n]


INPUT = [
    (3, ),
    (1, ),
    (4, ),
    (5, )
]