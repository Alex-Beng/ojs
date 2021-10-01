#
# @lc app=leetcode.cn id=453 lang=python3
#
# [453] 最小操作次数使数组元素相等
#

# @lc code=start
class Solution:
    def minMoves(self, nums: [int]) -> int:
        minn = min(nums)
        return sum(
            [i-minn for i in nums]
        )
# @lc code=end

