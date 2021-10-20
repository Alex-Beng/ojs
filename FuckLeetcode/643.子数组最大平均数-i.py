#
# @lc app=leetcode.cn id=643 lang=python3
#
# [643] 子数组最大平均数 I
#

# @lc code=start
class Solution:
    def findMaxAverage(self, nums: [int], k: int) -> float:
        n = len(nums)

        ts = sum(nums[:k])
        ans = ts
        for i in range(k, n):

            ts -= nums[i-k]
            ts += nums[i]
            ans = max(ans, ts)
        return ans/k
            
# @lc code=end

