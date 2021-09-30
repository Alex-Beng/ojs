#
# @lc app=leetcode.cn id=338 lang=python3
#
# [338] 比特位计数
#

# @lc code=start
class Solution:
    def countBits(self, n: int) -> [int]:
        dp = [0]*(n+23)
        dp[1] = 1
        for i in range(2, n+1):
            if i&1:
                dp[i] = dp[i-1]+1
            else:
                dp[i] = dp[i>>1]
        return dp[:n+1]
# @lc code=end
s = Solution()
r = s.countBits(
    100
)
print(r)