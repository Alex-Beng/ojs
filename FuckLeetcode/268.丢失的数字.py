#
# @lc app=leetcode.cn id=268 lang=python3
#
# [268] 丢失的数字
#

# @lc code=start
class Solution:
    def missingNumber(self, nums: [int]) -> int:
        nsum = sum(nums)
        n = len(nums)
        return n*(n+1)//2-nsum
# @lc code=end

