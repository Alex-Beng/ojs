#
# @lc app=leetcode.cn id=896 lang=python3
#
# [896] 单调数列
#

# @lc code=start
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        n = len(nums)
        diff = [nums[i]-nums[i-1] for i in range(1, n)]+[0]
        return min(diff)>=0 and max(diff)>=0 or max(diff)<=0 and min(diff)<=0
# @lc code=end