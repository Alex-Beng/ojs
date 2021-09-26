#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: [int]) -> int:
        n = len(nums)
        e = 0
        ts = 0
        ans = n+1
        for b in range(n):
            ts -= nums[b-1] if b!=0 else 0
            while ts < target and e<n:
                ts += nums[e]
                e += 1
            if ts >= target:
                ans = min(ans, e-b)
        return ans if ans != n+1 else 0
            
# @lc code=end

