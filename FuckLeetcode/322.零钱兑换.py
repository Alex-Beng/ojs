#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
from functools import lru_cache
class Solution:
    def coinChange(self, coins: [int], amount: int) -> int:
        nc = len(coins)

        @lru_cache(None)
        def dfs(amt: int) -> int:
            if amt<0:
                return float('inf')
            elif amt==0:
                return 0

            ans = float('inf')
            for c in coins:
                t = dfs(amt-c)
                ans = min(ans, t)
            return ans+1
        return dfs(amount) if dfs(amount) != float('inf') else -1
# @lc code=end

s = Solution()
res = s.coinChange(
    # [1,2,5],11
    [3,7,405,436], 8839
)
print(res)