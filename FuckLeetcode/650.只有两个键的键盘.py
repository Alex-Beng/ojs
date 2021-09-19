#
# @lc app=leetcode.cn id=650 lang=python3
#
# [650] 只有两个键的键盘
#

# @lc code=start
from math import sqrt
class Solution:
    def minSteps(self, n: int) -> int:
        dp = [float('inf')]*(n+1)
        dp[1] = 0
        for i in range(2, n+1):
            for j in range(1, int(sqrt(i)+1)):
                # factor
                if i%j == 0:
                    dp[i] = min(dp[i], dp[j]+i//j)
                    dp[i] = min(dp[i], dp[i//j]+j)
        # print(dp)
        return dp[n]
            
# @lc code=end

