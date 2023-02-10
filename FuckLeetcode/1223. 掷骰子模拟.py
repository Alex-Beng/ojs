from functools import lru_cache
from typing import List

class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:

        @lru_cache(None)
        def dp(i, j):
            nonlocal rollMax
            if i<=0:
                return 0
            # 以j结尾的长度为i的序列数量
            # 问题：i >= max(rollMax)+1时
            # dp[i, j] 的j不知道前面有几个j
            m = rollMax[j-1]
            t_sum = 0
            for jlen in range(1, m+1):
                if jlen == i:
                    t_sum += 1
                    break
                for tj in range(1, 7):
                    if tj == j:
                        continue
                    t_sum += dp(i-jlen, tj)
            return t_sum % (10**9+7)
        res = [dp(n, j) for j in range(1, 7)]
        return sum(res)%(10**9+7)
        @lru_cache(None)
        def dp(i, j, k):
            nonlocal rollMax
            # 长度为i，连续k个j的序列数
            if i==n:
                return 1
            t_sum = 0
            # 枚举下一个
            for tj in range(1, 7):
                if tj == j:
                    if k+1 <= rollMax[j-1]:
                        t_sum += dp(i+1, j, k+1)
                else:
                    t_sum += dp(i+1, tj, 1)
            return t_sum % (10**9+7)
        print(sum(res) % (10e9+7), sum(res))
        print(sum(res) %(10**9+7), dp(0, 0, 0))
        return dp(0, 0, 0)
s = Solution()
r = s.dieSimulator(
    # 2, [1,1,2,2,2,3]
    # 2, [1,1,1,1,1,1]
    # 3, [1,1,1,2,2,3]
    12, [8,5,10,8,7,2]
)
print(r)