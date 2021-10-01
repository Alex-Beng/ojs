#
# @lc app=leetcode.cn id=485 lang=python3
#
# [485] 最大连续 1 的个数
#

# @lc code=start
class Solution:
    def findMaxConsecutiveOnes(self, nums: [int]) -> int:
        nums += [0]
        for i,n in enumerate(nums):
            if n == 1:
                nums[i] = nums[i-1]+nums[i]
        return max(nums)
# @lc code=end

