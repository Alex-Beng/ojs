#
# @lc app=leetcode.cn id=292 lang=python3
#
# [292] Nim 游戏
#

# @lc code=start
class Solution:
    def canWinNim(self, n: int) -> bool:
        return n%4!=0
        # dp = [0]*(5)
        # dp[1] = dp[2] = dp[3] = 1
        # dp1 = dp2 = dp3 = 1
        # for i in range(4, 100):
        #     t = 0
        #     if dp1==0 or dp2==0 or dp3==0:
        #         t = 1
        #     print(t, end=' ')
        #     dp1, dp2, dp3 = dp2, dp3, t
        #     # for j in range():
        #     #     if dp[j] == 0:
        #     #         dp[i] = 1
        #     #         break
        # # print(dp)
        # return dp3==1
s = Solution()
s.canWinNim(
    1348820612
)
# @lc code=end

