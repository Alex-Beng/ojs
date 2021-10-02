#
# @lc app=leetcode.cn id=495 lang=python3
#
# [495] 提莫攻击
#

# @lc code=start
class Solution:
    def findPoisonedDuration(self, timeSeries: [int], duration: int) -> int:
        n = len(timeSeries)
        ans = 0
        timeSeries.append(float('inf'))
        for i in range(n):
            t = timeSeries[i]
            if t+duration <= timeSeries[i+1]:
                ans += duration
            else:
                ans += (timeSeries[i+1]-t)
        return ans
# @lc code=end

