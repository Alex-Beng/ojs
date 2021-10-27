#
# @lc app=leetcode.cn id=494 lang=python3
#
# [494] 目标和
#

# @lc code=start
from functools import lru_cache
class Solution:
    def findTargetSumWays(self, nums: [int], target: int) -> int:
        sums = sum(nums)
        wanted = sums+target
        if wanted&1:
            return 0
        wanted //= 2

        @lru_cache(None)
        def dfs(k: int, i: int) -> int:
            if k==0:
                return 1 if i==0 else 0
            if i<0:
                return 0
            return dfs(k-1, i-nums[k-1]) + dfs(k-1, i)

        return dfs(len(nums), wanted)

# @lc code=end
s = Solution()
r = s.findTargetSumWays(
    [27,22,39,22,40,32,44,45,46,8,8,21,27,8,11,29,16,15,41,0], 10
)
print(r)
