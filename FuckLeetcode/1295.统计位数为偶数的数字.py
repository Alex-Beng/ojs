#
# @lc app=leetcode.cn id=1295 lang=python3
#
# [1295] 统计位数为偶数的数字
#

# @lc code=start
class Solution:
    def findNumbers(self, nums: [int]) -> int:
        return sum([0 if len(str(n))&1 else 1 for n in nums])
# @lc code=end

