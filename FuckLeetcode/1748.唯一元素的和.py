#
# @lc app=leetcode.cn id=1748 lang=python3
#
# [1748] 唯一元素的和
#

# @lc code=start
class Solution:
    def sumOfUnique(self, nums: [int]) -> int:
        return sum([n for n in nums if nums.count(n)==1])
# @lc code=end

