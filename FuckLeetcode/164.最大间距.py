#
# @lc app=leetcode.cn id=164 lang=python3
#
# [164] 最大间距
#

# @lc code=start
class Solution:
    def maximumGap(self, nums: [int]) -> int:
        nums.sort()
        return max([
            nums[i]-nums[i-1] for i,n in enumerate(nums)
        ])
# @lc code=end

